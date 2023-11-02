# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Aufgaben der Programmierübung

### Aufgabe 1

Schreibe eine Funktion, die den Speicher des Bildes löscht, d.h. der vector soll geleert werden.

```cpp
void clear_image();
```

### Aufgabe 2

Schreibe eine Funktion, die die Größe des Bildes verändert, d.h. die Höhe oder Breite des Bildes wird verändert.

```cpp
void resize_image(const std::uint32_t new_width, const std::uint32_t new_height);
```

Wenn eine Dimension (Höhe oder Breite) des Bildes größer wird, soll die Matrix des Bildes mit 0 aufgefüllt werden.

### Konsolen-Output

![alt](./../../media/Exercise8_1.png)

### Aufgabe 3

Schreibe eine Funktion, die das Bild komplett mit einer Farbe füllt.

```cpp
void fill_image(const std::uint8_t value);
```

Die Füll-Farbe ist durch die Variable value gegeben.

### Aufgabe 4 (Zusatzaufgabe)

Schreibe eine Funktion, die eine horizontale bzw. vertikale Gerade auf das Bild malt.

```cpp
void draw_line(const std::uint32_t x1, const std::uint32_t y1,
	           const std::uint32_t x2, const std::uint32_t y2,
	           const std::uint8_t value);
```

### Beispiel-Bild

![alt](./../../media/Exercise8_2.bmp)
