#include <cmath>
#include <iostream>
#include <vector>

// 1.) Schreibe eine Function, die einen Vector mit aufsteigenden Werten befüllt
void fill_vector(std::vector<double> &vec)
{
}

// 2.) Schreibe eine Function, die die Werte eines Vectors ausgibt
void print_vector(const std::vector<double> &vec)
{
}

// 3.) Schreibe Funktionen, die die Exponential Werte berechnet
// verwendet std::exp, std::log aus <cmath>
void exp_vector(std::vector<double> &vec)
{
}

// 3.) Schreibe Funktionen, die die Natural Logarithm Werte berechnet
// verwendet std::exp, std::log aus <cmath>
void log_vector(std::vector<double> &vec)
{
}

int main()
{
    auto my_vector = std::vector<double>(3, 0.0);

    fill_vector(my_vector);
    print_vector(my_vector);

    exp_vector(my_vector);
    print_vector(my_vector);

    log_vector(my_vector);
    print_vector(my_vector);

    return 0;
}
