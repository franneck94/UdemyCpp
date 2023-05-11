# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Aufgaben der Programmierübung

### Aufgabe 1

Erstellt zunächst ein Double Pointer Array mit 100 Elementen, deren Wert die Zahlen von 0 bis 99 abspeichert (Tipp: for-Schleife nutzen).  

Schreibt dann eine Funktion,

```cpp
double array_sum(double *p_array, const std::size_t length)
```

die ein Pointer Array vom Typ double entgegennimmt (1. Argument), die Länge des Arrays entgegennimmt (2. Argument) und die Summe des Arrays berechnet und zurückgibt.

### Beispiel 1

Das heißt bei dem Array mit 100 Elementen würde folgende Summe heraus kommen:

```cpp
auto *d = new double[100];
// Hier Array-Werte init.
auto sum = array_sum(d, 100);
std::cout << sum << std::endl; // Ergebnis ist: 4950
```

## Aufgabe 2

Schreibt eine Funktion

```cpp
std::int32_t* array_constructor(const std::int32_t value, const std::size_t length)
```

die ein Pointer Array vom Typ int erstellt und zurückgibt.  
Dabei ist zu beachten, dass die Länge des Arrays und welcher Wert an jedem Index des Arrays abgespeichert werden soll, übergeben wird.

### Beispiel 2

```cpp
// value: 5, length: 3
auto* array = array_constructor(5, 3)
// array = { 5, 5, 5}
```

Das heißt wenn ihr sagt, dass Array soll 3 Elemente haben und der Wert ist 5, resultiert ein Array mit 3 Indizes, bei denen überall der Wert 5 ist.
