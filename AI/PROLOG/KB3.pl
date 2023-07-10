happy(bigyan).
listens2Music(adi).
playsAirGuitar(bigyan):-
    listens2Music(bigyan),
    happy(bigyan).
playsAirGuitar(adi):-
    happy(adi).
playsAirGutiar(adi):-
    listens2Music(adi).

