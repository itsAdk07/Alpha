edge(s,a).
edge(b,d).
edge(c,d).
edge(a,c).
edge(s,b).
edge(d,e).
edge(e,g).
edge(d,f).

%termination cond

route(X,Z):-
    edge(X,Y),
    edge(Y,Z),
    write(Y),
    write('->'),
    write(Z).

%recursion
route(X,Z):-
    edge(X,CV),
    route(CV,Z).


