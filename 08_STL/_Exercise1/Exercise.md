# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Aufgaben der Programmierübung

### Beschreibung

Wir haben einen binären Zufallsvektor "target" in der Main Funktion, mit einer Länge von 20 Elementen.  
Dessen Werte wurden bereits zufällig permutiert und in einem neuen Vektor "input" abgespeichert.

Also z.b.  
[0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0]

### Aufgabe 1

Schreibt eine Funktion

```cpp
vector<bool> shuffle_till_equal(const BinaryArray &target, BinaryArray input);
```

Die einen binären Vektor "target" und einen binären Vektor "input" entgegennimmt.  
Bei jeder Iteration muss überprüft werden, ob die beiden Vektoren die gleichen Werte haben.  
Sofern das so ist, kann die Funktion terminieren.  
Sofern das nicht der Fall ist, soll das (ganze) Input Arrays erneut ge-shuffelt werden.

### Beispiel Aufgabe 1

![alt](./../../media/Exercise7_2.png)

### Aufgabe 2

Jetzt wollen wir eine effizientere Version programmieren.

```cpp
vector<bool> smart_shuffle_till_equal(const BinaryArray &target, BinaryArray input);
```

Diese soll nicht immer den kompletten Vector Shuffeln, sondern nur ab dem Index, bei dem der erste unterschiedliche Wert auftaucht. (Vom Anfang des Vectors aus gesehen).  
Führt diese Funktion ebenfalls aus und misst ebenfalls die Zeit.

### Beispiel Aufgabe 2

![alt](./../../media/Exercise7_3.png)
