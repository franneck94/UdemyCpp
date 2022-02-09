# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Vorwort

In dieser Programmierübung wollen wir uns überlegen, wie wir "Dynamische Arrays" implementieren können.  
Diese beschreiben Heap-Arrays, bei denen man während der Laufzeit des Programms die Größe ändern kann, indem man entweder neuen Speicher auf dem Heap reserviert, oder Speicher wieder freigibt. (Stichwort: new und delete)  
Diese Dynamischen Arrays werden später in der Standard-Bibliothek "Vector" (Vektoren) genannt.

## Aufgaben der Programmierübung

### Aufgabe 1

Schreibe eine Funktion

```cpp
void push_back(int* &input_array, const unsigned int &size, const int &value);
```

die ein Element am Ende des dynamischen Arrays hinzufügt. Beachte dabei, dass sich somit die Länge des Arrays um Eins erhöht.

### Aufgabe 2

Schreibe eine Funktion

```cpp
void pop_back(int* &input_array, const unsigned int &size);
```

die das letzte Element des dynamischen Arrays entfernt. Beachte dabei, dass sich somit die Länge des Arrays um Eins reduziert.

## Hinweise

Der Udemy Compiler überprüft nur, ob ihr eine Lösung abgegeben habt.  
Meine Musterlösung werde ich im folgenden Video vorstellen.
