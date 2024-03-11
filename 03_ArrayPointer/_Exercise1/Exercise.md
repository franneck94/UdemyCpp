# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Aufgaben der Programmier-Übung

### Aufgabe 1

Erstellt zunächst ein double-array mit 100 Elementen, deren Wert die Zahlen von 0 bis 99 abspeichert.

### Aufgabe 2

Schreibt dann diese Funktion,

```cpp
double array_sum(const double array[], const std::size_t length)
```

Es soll die Summe des Arrays berechnet und zurückgegeben werden.

### Beispiel 2

Das heißt, bei dem Array mit 100 Elementen würde folgende Summe herauskommen:

```cpp
double a[100] = {0, 1, ..., 99};
// Hier Array-Werte init.
double sum = array_sum(a, 100);
std::cout << sum << std::endl; // Ergebnis ist: 4950
```

### Aufgabe 3

Erstellt zunächst ein Double std::array mit 100 Elementen, deren Wert die Zahlen von 0 bis 99 abspeichert.

Schreibt dann diese Funktion,

```cpp
double array_sum(const std::array<double, 100> array)
```

Es soll die Summe des std::arrays berechnet und zurückgegeben werden.

### Beispiel 3

Das heißt, bei dem Array mit 100 Elementen würde folgende Summe herauskommen:

```cpp
std::array<double, 100> a = {0, 1, ..., 99};
// Hier Array-Werte init.
double sum = array_sum(a, 100);
std::cout << sum << std::endl; // Ergebnis ist: 4950
```
