# Coding Project 1

## Disclaimer

Ich werde meine Lösung Schritt-für-Schritt live programmieren.  
Deswegen müsst ihr diese nicht selber lösen, ihr könnt es aber gerne probieren.

## Exercise 1

Implementiere die folgenden Funktionen für das DynamicArray struct

```cpp
struct DynamicArray
{
    double *m_data;
    std::size_t m_length;
};

double sum(const DynamicArray &dynamic_array)

double mean(const DynamicArray &dynamic_array)

double median(const DynamicArray &dynamic_array)
```
Beachte dabei, dass der Mean (Mittelwert) und der Median unterschiedliche Sachen sind.  
Außerdem kann man eine der Funktionen bei einer anderen wiederverwenden.   
