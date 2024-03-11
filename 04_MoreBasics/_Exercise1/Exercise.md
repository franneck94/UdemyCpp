# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Aufgaben der Programmierübung

### Aufgabe 1

Implementiert folgende Funktionen in der exercise.h:

```cpp
template <...>
double mean_array_value(...int array ...)

template <...>
double mean_array_value(...double array ...)
```

Die erste Funktion soll den Mittelwert (Mean) des Int-Arrays berechnen.  
Die zweite Funktion soll denMittelwert (Mean) des Double-Arrays berechnen.  
ACHTUNG: Bitte verwendet std::array's!

Das heißt wir haben hier eine Funktions-Überladung (Overloading), für verschiedene Datentypen.  
Die beiden Funktionen sollen innerhalb des Namespaces "computation" implementiert werden.

### Beispiel Aufgabe 1

```cpp
#include <array>
#include <cstdint>
#include <iostream>

#include "exercise.h"

int main()
{
    // Exercise 1
    const auto array_elements = 5;
    std::array<int, array_elements> array_a = {1, 2, 3, 4, 5};
    std::array<double, array_elements> array_b = {1.0, 2.5, 3.5, 4.5, 10.0};

    const auto mean_array_a = computation::mean_array_value(array_a);
    const auto mean_array_b = computation::mean_array_value(array_b);

    std::cout << "Mean Array A: " << mean_array_a << '\n';
    std::cout << "Mean Array B: " << mean_array_b << '\n';

    return 0;
}
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

Die Definition der Struktur soll ebenfalls im Namespace "computation" in der Datei "exercise.h" geschehen.  
Legt dann in der Main Funktion eine Variable dieser Struktur an und speichert die Mittelwerte von Aufgabe 1 ab.
