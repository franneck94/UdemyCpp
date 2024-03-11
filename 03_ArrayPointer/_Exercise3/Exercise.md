# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Vorwort

In dieser Programmier-Übung wollen wir uns überlegen, wie wir "Dynamische Arrays" implementieren können.  
Diese beschreiben Heap-Arrays, bei denen man die Größe ändern kann.  
Indem man entweder neuen Speicher auf dem Heap reserviert, oder Speicher wieder freigibt. (Stichwort: new und delete)
Diese dynamischen Arrays werden später in der Standard-Bibliothek "Vector" (Vektoren) genannt.  

## Aufgaben der Programmierübung

### Aufgabe 1

Schreibe eine Funktion

```cpp
void push_back(
    std::int32_t* &input_array,
    const std::size_t size,
    const std::int32_t value);
```

die ein Element am Ende des dynamischen Arrays hinzufügt. Beachte dabei, dass sich somit die Länge des Arrays um eins erhöht.

### Aufgabe 2

Schreibe eine Funktion

```cpp
void pop_back(
    std::int32_t* &input_array,
    const std::size_t size);
```

die das letzte Element des dynamischen Arrays entfernt. Beachte dabei, dass sich somit die Länge des Arrays um eins reduziert.

### Beispiel

```cpp
std::uint32_t size = 3;
std::int32_t *my_data = new std::int32_t[size];

my_data[0] = 0;
my_data[1] = 1;
my_data[2] = 2;

// Vorher: 0, 1, 2, Länge = 3
push_back(my_data, size, 12);
size++;
// Nachher: 0, 1, 2, 12, Länge = 4

// Vorher: 0, 1, 2, 12, Länge = 4
pop_back(my_data, size);
size--;
// Nachher: 0, 1, 2, Länge = 3
```
