#include <iostream>
#include <vector>
#include <cmath>

void fill_double_vector(std::vector<double> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = i;
    }
}

void print_double_vector(const std::vector<double> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << std::endl;
    }

    std::cout << std::endl;
}

void double_vector_exp(std::vector<double> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = std::exp(vec[i]);
    }
}

void double_vector_log(std::vector<double> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = std::log(vec[i]);
    }
}

int main()
{
    // Exercise:
    // 1.) Schreibe eine Funktion, die einen double-Vector mit aufsteigenden double-Werten befüllt
    // => z.b. [0.0, 1.0, 2.0, 3.0, 4.0, 5.0] bei einem Input Vector der Länge 6
    // void fill_double_vector(std::vector<double> &vec)
    // 2.) Schreibe eine Funktion, die die Werte eines double-Vectors in der Konsole ausgibt
    // void print_double_vector(const std::vector<double> &vec)
    // 3.) Schreibe Funktionen, die die:
    // - Exponential
    // - Natural Logarithm
    // Werte von einem double-Vector berechnet
    // Bsp: void double_vector_exp(std::vector<double> &vec) verwendet std::exp, std::log aus <cmath>
    // [exp(0.0), exp(1.0), ...]
    // [log(0.0), log(1.0), ...]

    //                            LENGTH, DEFAULT VALUE
    std::vector<double> my_vector(4, 0); // [0.0, 0.0, 0.0 ,0.0]

    fill_double_vector(my_vector); // [0.0, 1.0, 2.0, 3.0]
    print_double_vector(my_vector);

    double_vector_exp(my_vector); // [exp(...), exp(...), ...]
    print_double_vector(my_vector);

    double_vector_log(my_vector);	// log(exp(val) = val   [log(...), log(...), ...]
    print_double_vector(my_vector); // same output as in line 59

    return 0;
}
