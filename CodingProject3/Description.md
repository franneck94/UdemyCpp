# Coding Project 3

## Disclaimer

Ich werde meine Lösung Schritt-für-Schritt live programmieren.  
Deswegen müsst ihr diese nicht selber lösen, ihr könnt es aber gerne probieren.

## Exercise 1

Implementiere die folgenden Konstruktoren für die Matrix Template Klasse.

```cpp
template <typename T>
Matrix<T>::Matrix(const std::size_t rows, const std::size_t cols)

template <typename T>
Matrix<T>::Matrix(const std::size_t rows, const std::size_t cols, const T value)
```

Bei der ersten Version soll einfach alles mit 0 initialisiert werden.  
Bei der zweiten mit dem input Wert "value".  

## Exercise 2

Implementiere die folgenden Operatoren für die Matrix Template Klasse.

```cpp
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) const

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &scalar) const

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const T &scalar)

template <typename T>
Matrix<T> Matrix<T>::operator/(const T &scalar) const

template <typename T>
Matrix<T> &Matrix<T>::operator/=(const T &scalar)

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs) const

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix &rhs)
```

Um die Operatoren zu Implementieren muss natürlch bekannt sein, wie diese mathematischen Operationen zu implementieren sind.  
Wenn ihr das nicht (mehr) wisst, dann schaut euch direkt meine Videos an.

## Exercise 3

Zum Abschluss gibt es noch 2 getter-Funktionen.

```cpp
template <typename T>
std::size_t Matrix<T>::num_rows() const

template <typename T>
std::size_t Matrix<T>::num_cols() const
```

Diese Funktionen sollten ja easy machbar sein für euch ;)
