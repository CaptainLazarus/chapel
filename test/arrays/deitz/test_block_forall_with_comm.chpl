use BlockDist;

const D = [1..4] distributed Block([1..4]);

class C {
  var i: int;
}

var c = new C();

forall i in D {
  writeln(c.i);
}

var A: [D] int;

forall e in A {
  writeln(c.i);
}
