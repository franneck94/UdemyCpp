# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Vorwort

In dieser Programmierübung sollen bei allen Aufgaben Lambda Ausdrücke verwendet werden.
Der ganze Code ist in der Lambda.cc Datei (innerhalb der Main Funktion) gegeben.
Dabei werden wir mit dem Vector **my_vector** und **my_result** die kommenden Aufgaben ausführen.

## Aufgaben der Programmierübung

### Aufgabe 1

Überprüfe beim Vector my_vector, ob dieser keine Geraden Werte enthält und gebe das Ergebnis in der Konsole aus.

```cpp
bool has_no_even = ...;
if(has_no_even)
{
    std::cout << "None of the vector values are even" << std::endl;
}
else
{
    std::cout << "The vector has even numbers" << std::endl;
}
```

### Aufgabe 2

Speichere die quadrierten Werte von **my_vector** in **my_result** ab und gebe diese in der Konsole aus.

```cpp
... // Square the values

for (const auto &val : my_result)
{
    std::cout << val << std::endl;
}
```
