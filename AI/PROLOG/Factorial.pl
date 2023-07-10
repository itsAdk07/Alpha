%Factorial Problem.
fact(N):-
    fact(N,1).

%terminating condition.

fact(N,FV):-
    N<2,
    write('Factorial='),
    write(FV),
    nl.


fact(N,FV):-
    N>=2,
    NewFV is FV*N,
    NewN is N-1,
    fact(NewN, NewFV).

