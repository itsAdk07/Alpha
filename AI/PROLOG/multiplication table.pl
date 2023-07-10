Mtable(N):-
mtable(N,1).
% 1 - boundary
mtable(_N,P):-
    P>10.
% 2 - recursive
mtable(N,P):-
    Val is N*P,
    write(N),
    write(' * '),
    write(P),
    write( = ),
    write(Val),
    nl,
    NewP is P+1,
    mtable(N,NewP).
