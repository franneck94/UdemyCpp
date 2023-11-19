# Coding Project 5

## Disclaimer

Ich werde meine Lösung Schritt-für-Schritt live programmieren.  
Deswegen müsst ihr diese nicht selber lösen, ihr könnt es aber gerne probieren.

## Exercise 1

Für diese Methoden wollen wir jetzt die Möglichkeit bieten, die Rechnung auch parallel mit openmp auszuführen.

```cpp
template <std::floating_point T>
Matrix<> Matrix<T>::operator*(const Matrix<T> &rhs) const
```

Das lohnt sich natürlich erst bei größeren Matrizen.
Das wird unsere Bedingung sein, ob die Matrix **noch nicht** groß genug ist:

```cpp
if ((m_rows < 250 && m_cols < 250) ||
    (rhs.m_rows < 250 && rhs.m_cols < 250))
```

Wenn das der Fall ist, führen wir die Berechnung aus, wie aus dem letzten Coding Project.  
Wenn die Matrix aber groß genug ist, wird unsere neue Funktion aufgerufen.
