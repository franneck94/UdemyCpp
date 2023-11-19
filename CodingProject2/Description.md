# Coding Project 2

## Disclaimer

Ich werde meine Lösung Schritt-für-Schritt live programmieren.  
Deswegen müsst ihr diese nicht selber lösen, ihr könnt es aber gerne probieren.

## Exercise 1

Implementiere die folgenden Funktionen für die DynamicArray Template Klasse.

```cpp
template <typename T>
DynamicArray<T>::DynamicArray()

template <typename T>
DynamicArray<T>::DynamicArray(const T &value, const std::size_t length)

template <typename T>
DynamicArray<T>::~DynamicArray()

template <typename T>
void DynamicArray<T>::push_back(const T &value)

template <typename T>
void DynamicArray<T>::pop_back()

template <typename T>
T &DynamicArray<T>::operator[](const std::size_t index)

template <typename T>
const T &DynamicArray<T>::operator[](const std::size_t index) const

template <typename T>
std::size_t DynamicArray<T>::get_length() const
```

Vieles kann in abgewandelter Form von dem CodingProject1 kopiert werden.  
Eigentlich ist ja nur neu, dass es jetzt ein template typename T ist, vorher war es ja ein festgelegter Datentyp.  
Wirklich neu ist aber die Operator-Überladung für den Index-Operator ([]).  
Dort wollen wir auf das darunterliegende Array zugreifen.  
