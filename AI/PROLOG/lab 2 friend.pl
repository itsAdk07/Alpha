friend(a,b).
friend(b,c).
friend(c,d).
%terminatingcondition
friendoffriend(X,Y):-
    friend(X, CommonPerson),
    friend(CommonPerson, Y).
%recursivecondition
friendoffriend(X, Y):-
    friend(X, CommonPerson),
    friendoffriend(CommonPerson,Y).

edge(a,b).
edge(b,c).
edge(c,d).
%terminating condition
path(X,Y):-
    edge(X, CommonPath),
    edge(CommonPath, Y).

%recursive condition
path(X,Y):-
    edge(X, CommonPath),
    path(CommonPath, Y).


