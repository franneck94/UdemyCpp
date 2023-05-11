# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Aufgaben der Programmierübung

### Aufgabe 1

Implementiert folgende Funktionen:

```cpp
double mean_array_value(int *array, const std::size_t length);
double mean_array_value(double *array, const std::size_t length);
```

Die erste Funktion soll den Mittelwert (Mean) des Int-Arrays berechnen.  
Die zweite Funktion soll denMittelwert (Mean) des Double-Arrays berechnen.  

Das heißt wir haben hier eine Funktions-Überladung (Overloading), für verschiedene Datentypen.  
Die beiden Funktionen sollen innerhalb des Namespaces "computation" in der exercise.h deklariert und in der exercise.cc definiert werden.

### Beispiel Aufgabe 1

```cpp
const std::uint32_t array_elements = 5;
int array_a[array_elements] = { 1, 2, 3, 4, 5 };
double array_b[array_elements] = { 1.0, 2.5, 3.5, 4.5, 10.0 };

double mean_array_a = computation::mean_array_value(array_a, array_elements);
double mean_array_b = computation::mean_array_value(array_b, array_elements);

// Ausgabe ist: Mean Array A: 3 
std::cout << "Mean Array A: " << mean_array_a << std::endl;
// Ausgabe ist: Mean Array B: 4.3
std::cout << "Mean Array B: " << mean_array_b << std::endl;
```

### Aufgabe 2

Erstellt eine Struktur "struct Dataset" mit den folgenden Attributen: mean_array_a und mean_array_b.

### Beispiel 2

```cpp
struct Dataset
{
    TYPE ...;
    TYPE ...;
};
```

Die Definition der Struktur soll ebenfalls im Namespace "computation" in der Datei "exercise.h" geschehen.Legt dann in der Main Funktion eine Variable dieser Struktur an und speichert die Mittelwerte von Aufgabe 1 ab.
