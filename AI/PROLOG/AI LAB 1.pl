boy(bigyan).
girl(prakriti).
club(arsenal).
sports(football).
sports(cricket).
sports(basketball).
subjects(ai,os,dbms,cn,toc).

games.
games(valorant).
games(minecraft).
games(fifa).

happy(bigyan).
playsFootball(bigyan).
playsFootball(prakriti):-
    watchesFootball(prakriti).
watchesFootball(prakriti).

son(bigyan).
son(pratik).
man(bigyan).
children(X):-
    son(X),
    man(X).

likes(bigyan, pizza).
likes(bigyan, chocolate).

friend(X, Y) :-
    likes(X, Z),
    likes(Y, Z),
    X \= Y.

food_friends(X, Y) :-
    friend(X, Y),
    likes(X, Food),
    likes(Y, Food).

is_food_friend(X) :-
    food_friends(bigyan, X).


% Facts: Parent-child relationships
parent(durga, bigyan).
parent(nirmala, bigyan).
parent(durga, anushka).
parent(nirmala, anushka).
parent(durga, simrika).
parent(nirmala, simrika).

% Rules: Relationships
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).
sister_in_law(X, Y) :- parent(Z, X), sibling(Z, W), parent(W, Y), female(X), X \= Y.
brother_in_law(X, Y) :- parent(Z, X), sibling(Z, W), parent(W, Y), male(X), X \= Y.
cousin(X, Y) :- parent(A, X), parent(B, Y), sibling(A, B), X \= Y.
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

% Facts: Gender
female(nirmala).
female(anushka).
female(simrika).
female(durga).
male(bigyan).
male(binay).

parent(durga, bigyan).
parent(nirmala, bigyan).
parent(durga, anushka).
parent(nirmala, anushka).



