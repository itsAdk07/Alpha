%Terminating Condition.
count(LB,UB):-
    LB>UB.
count(LB,UB):-
    LB=<UB,
    write(LB),
    nl,
    NewLB is LB+1,
    count(NewLB,UB).

% Task is to modify this program so as to print the number in reverse
% order
% Task is to modify this program so as to print the number in negative
% one


