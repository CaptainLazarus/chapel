/***************************************************************
This code was generated by  Spiral 5.0 beta, www.spiral.net --
Copyright (c) 2005, Carnegie Mellon University
All rights reserved.
The code is distributed under a BSD style license
(see http://www.opensource.org/licenses/bsd-license.php)

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above copyright
  notice, reference to Spiral, this list of conditions and the
  following disclaimer.
* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the following
  disclaimer in the documentation and/or other materials provided
  with the distribution.
* Neither the name of Carnegie Mellon University nor the name of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*AS IS* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************/

#ifndef OMEGA_64C_H_INCLUDED
#ifdef __cplusplus
#include <cmath>
#include <cstdlib>
#include <complex>
using namespace std;
#else
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#endif
#define PI    3.14159265358979323846

#ifdef __GNUC__
#ifdef __cplusplus
#define __I__ complex<double>(0,1)
#define complex_t complex<double>
#else
#define complex_t _Complex double
#define __I__ _Complex_I
#endif
#endif

#ifdef __ICL
#define complex_t _Complex double
#endif

static complex_t omega(int N, int k) { return cos(2*PI*(k%N)/N) + __I__ * sin(2*PI*(k%N)/N); }

static double cospi(double a) { return cos(PI*a); }

static double sinpi(double a) { return sin(PI*a); }

#define RE_CPX(x) (creal(x))
#define IM_CPX(x) (cimag(x))

#if defined(_WIN32) || defined(_WIN64)
#define MALLOC(a) _mm_malloc(a, 16)
#else
#include <malloc.h>
#define MALLOC(a) memalign(16, a)
#endif

#endif

