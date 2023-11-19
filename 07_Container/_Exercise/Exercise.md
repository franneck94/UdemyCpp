# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Vorwort

Wir werden in dieser Übung ein Alias Type verwenden:

```cpp
#include <utility>
#include <map>
#include <string>
#include <cstdint>

using Friends = std::map<std::string, std::pair<std::int32_t, std::int32_t>>;
```

## Aufgaben der Programmierübung

### Aufgabe 1

Erstelle in deiner Main Funktion eine Map vom Typ Friends.Die Map speichert ein Pair mit den Attributen "Alter" (int) und "Gewicht" (int)  zu dem jeweiligen Namen einer Person (key) ab.
Füge dieser Map min. 2 Personen hinzu.

### Aufgabe 2

Erstelle die Funktionen

```cpp
std::string_view get_oldest_friend(const Friends &friends);
std::string_view get_heaviest_friend(const Friends &friends);
```

Um die älteste Person bzw. die schwerste Person aus deiner Map auszugeben.
Wende beide Funktionen auf die Map deiner Freunde an und gebe die Daten aus.
Das heißt, bestimme, wer die älteste und wer die schwerste Person ist.
