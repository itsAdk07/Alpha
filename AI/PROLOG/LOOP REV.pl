%terminating condition.
countrev(UB,LB):-
    UB<LB.

countrev(UB, LB):-
    UB>=LB,
    write(UB),
    nl,
    NewUB is UB-1,
    countrev(NewUB, LB).

