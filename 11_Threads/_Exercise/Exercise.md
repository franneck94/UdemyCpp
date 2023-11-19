# Exercise

Hallo Leute!

Willkommen bei der nächsten Programmier-Übung in diesem Kurs.

## Aufgaben der Programmierübung

### Aufgabe 1

Implementiere eine Funktion die die Summe eines Vectors mit mehreren Threads berechnet.  
Dabei soll dann der Vector in gleich große Teile aufgeteilt werden und jeder Thread kümmert sich dann um eine Teilsumme.  
Diese Teilsummen sollen dann am Ende aufaddiert werden. Mit dieser *Teilsummen* Methode benötigen wir keine Mutexes.  

```cpp
template <typename It, typename T>
void sum_slice(It first, It last, T &result)
{
    result = std::accumulate(first, last, T{});
}

template <typename T>
T parallel_sum(std::vector<T> &vec)
{
    T final_sum = 0;


    return final_sum;
}
```
