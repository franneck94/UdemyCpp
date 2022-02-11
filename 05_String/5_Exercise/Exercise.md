# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Vorwort

Wir werden in dieser Übung zwei typedefs verwenden:

```cpp
#include <vector>
using std::vector;

typedef unsigned char uchar;
typedef vector<uchar> ByteArray;
```

## Aufgaben der Programmierübung

### Aufgabe 1

Schreibt eine Funktion

```cpp
uchar hex_xor(uchar &hex1, uchar &hex2);
```

die zwei uchar Werte entgegennimmt und das Ergebnis der logischen XOR-Verknüpfung returned.

### Aufgabe 2

Schreibt eine Funktion

```cpp
ByteArray hex_vector_xor(ByteArray &vec1, ByteArray &vec2);
```

die zwei ByteArrays entgegennimmt und die einzelnen Werte der Arrays XORed. Das Ergebnis soll in einen neuen Vector (ByteArray) abgespeichert werden.
