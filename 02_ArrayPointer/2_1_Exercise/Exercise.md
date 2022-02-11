# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Aufgaben der Programmierübung

### Aufgabe 1

Erstellt zunächst ein Double Pointer Array mit 100 Elementen, deren Wert die Zahlen von 0 bis 99 abspeichert (Tipp: for-Schleife nutzen).  

Schreibt dann eine Funktion, 

```cpp
double array_sum(double *p_array, const unsigned int &length)
```

die ein Pointer Array vom Typ double entgegennimmt (1. Argument), die Länge des Arrays entgegennimmt (2. Argument) und die Summe des Arrays berechnet und zurückgibt.

### Beispiel

Das heißt bei dem Array mit 100 Elementen würde folgende Summe heraus kommen:

```cpp
double *d;
d = new double[100];
....
double sum = array_sum(d, 100);
std::cout << sum << std::endl; // Ergebnis ist: 4950
```

## Aufgabe 2

Schreibt eine Funktion 

```cpp
int* array_constructor(const int &value, const unsigned int &length)
```

die ein Pointer Array vom Typ int erstellt und zurückgibt. Dabei ist zu beachten, dass die Länge des Arrays und welcher Wert an jedem Index des Arrays abgespeichert werden soll, übergeben wird.

### Beispiel

```cpp
// length: 3, value: 5
int* array = array_constructor(5, 3)
// array = { 5, 5, 5}
```

Das heißt wenn ihr sagt, dass Array soll 3 Elemente haben und der Wert ist 5, resultiert ein Array mit 3 Indizes, bei denen überall der Wert 5 ist.
