%Fibonacci Series.
fib(N):-
    fib(0,1,N).

%terminating condition.
fib(_S1,_S2,N):-
    N<1.
%recursive call.
fib(S1,S2,N):-
    N>=1,
    write(S1),
    nl,
    NewS1 is S2,
    NewS2 is S1+S2,
    NewN is N-1,
    fib(NewS1,NewS2,NewN).

%Task: Multiplication table in PROLOG
