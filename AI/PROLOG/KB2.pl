happy(bigyan).
playsGuitar(bigyan).
playsGuitar(bigyan):-
    happy(bigyan).
excited(bigyan).
watchArsenal(bigyan).
exciter(bigyan):-
    watchArsenal(bigyan).

happy(yogita).
listens2music(yogita).
listens2music(yogita):-
    happy(yogita).
playsAirGuitar(ria):-
    kistens2music(ria).
playsAirGuitar(yogita):-
    listens2music(yogita).

