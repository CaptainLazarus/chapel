//===- ErrorCollector.cpp -------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===-----------------------------------------------------------------------===/

#include "ErrorCollector.h"
#include "llvm/Support/Errc.h"
#include "llvm/Support/Error.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/WithColor.h"
#include <vector>

using namespace llvm;
using namespace llvm::elfabi;

void ErrorCollector::escalateToFatal() {
  ErrorsAreFatal = true;
}

void ErrorCollector::addError(Error &&Err, StringRef Tag) {
  if (Err) {
    Errors.push_back(std::move(Err));
    Tags.push_back(Tag.str());
  }
}

Error ErrorCollector::makeError() {
  // TODO: Make this return something (an AggregateError?) that gives more
  // individual control over each error and which might be of interest.
  Error JoinedErrors = Error::success();
  for (Error &E : Errors) {
    JoinedErrors = joinErrors(std::move(JoinedErrors), std::move(E));
  }
  Errors.clear();
  Tags.clear();
  return JoinedErrors;
}

void ErrorCollector::log(raw_ostream &OS) {
  OS << "Encountered multiple errors:\n";
  for (size_t i = 0; i < Errors.size(); ++i) {
    WithColor::error(OS) << "(" << Tags[i] << ") " << Errors[i];
    if (i != Errors.size() - 1)
      OS << "\n";
  }
}

bool ErrorCollector::allErrorsHandled() const {
  return Errors.empty();
}

ErrorCollector::~ErrorCollector() {
  if (ErrorsAreFatal && !allErrorsHandled())
    fatalUnhandledError();

  for (Error &E : Errors) {
    consumeError(std::move(E));
  }
}

LLVM_ATTRIBUTE_NORETURN void ErrorCollector::fatalUnhandledError() {
  errs() << "Program aborted due to unhandled Error(s):\n";
  log(errs());
  errs() << "\n";
  abort();
}
