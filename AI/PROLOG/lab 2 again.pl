kills(yoru, viper).
kills(yoru, fade).
kills(viper, fade).
murder(X,Y):-
    kills(X, CommonPerson),
    kills(CommonPerson, Y).

