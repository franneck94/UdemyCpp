#include <cmath>
#include <iostream>
#include <vector>

// Aufgabe: Verwende ranged-based for loops für die Funktionen!

void fill_vector(std::vector<double> &vec)
{
    for (int i = 0; auto &value : vec)
    {
        value = static_cast<double>(i);
        i++;
    }
}

void print_vector(const std::vector<double> &vec)
{
    for (int i = 0; const auto &value : vec)
    {
        std::cout << "Vec[" << i << "] = " << value << '\n';
        i++;
    }
    std::cout << '\n';
}

void exp_vector(std::vector<double> &vec)
{
    for (auto &value : vec)
    {
        value = std::exp(value);
    }
}

void log_vector(std::vector<double> &vec)
{
    for (auto &value : vec)
    {
        value = std::log(value);
    }
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
