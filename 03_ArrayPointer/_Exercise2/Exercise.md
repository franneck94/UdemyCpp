# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Aufgabe

Schreibt eine Funktion

```cpp
std::int32_t* array_constructor(
    const std::int32_t value,
    const std::size_t length)
```

die ein Pointer Array vom Typ int erstellt und zurückgibt.
Dabei ist zu beachten, dass die Länge des Arrays und welcher Wert an jedem Index des Arrays abgespeichert werden soll, übergeben wird.

### Beispiel

```cpp
// value: 5, length: 3
auto* array = array_constructor(5, 3)
// array = { 5, 5, 5}
```

Das heißt wenn, ihr sagt das Array soll 3 Elemente haben und der Wert ist 5, resultiert ein Array mit 3 Indizes, bei denen überall der Wert 5 ist.
