# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Vorwort

Wir werden in dieser Übung ein Typedef verwenden:

```cpp
#include <utility>
#include <map>
#include <string>

using std::pair;
using std::map;
using std::string;

typedef map<string, pair<int, int>> Friends;
```

## Aufgaben der Programmierübung

### Aufgabe 1

Erstelle in deiner Main Funktion eine Map vom Typ Friends.Die Map speichert ein Pair mit den Attributen "Alter" (int) und "Gewicht" (int)  zu dem jeweiligen Namen einer Person (key) ab.  
Füge dieser Map min. 2 Personen hinzu.

### Beispiel Aufgabe 1

```cpp
Friends friends;

friends["Jan"] = ...;
friends["Peter"] = ...;
```

### Aufgabe 2

Erstelle die Funktionen

```cpp
string get_oldest_friend(const Friends &friends);
string get_heaviest_friend(const Friends &friends);
```

Um die älteste Person bzw. die schwerste Person aus deiner Map auszugeben.  
Wende beide Funktionen auf die Map deiner Freunde an und gebe die Daten aus.  
Das heißt, bestimme wer die älteste und wer die schwerste Person ist.
