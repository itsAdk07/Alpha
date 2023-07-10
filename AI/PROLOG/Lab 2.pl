loves(ram, sita).
loves(ravan, sita).
loves(sita, ram).
loves(harry, sejal).
loves(marcus, sejal).
loves(sejal, marcus).
jealous(X,Y):-
    loves(X, CommonPerson),
    loves(Y, CommonPerson),
    loves(CommonPerson, Y).
