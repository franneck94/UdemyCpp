#include <cmath>
#include <iostream>
#include <vector>

void fill_double_vector(std::vector<double> &vec)
{
    int i = 0;

    for (auto &value : vec)
    {
        value = static_cast<double>(i);
        i++;
    }
}

void print_double_vector(const std::vector<double> &vec)
{
    int i = 0;

    for (const auto &value : vec)
    {
        std::cout << "Vec[" << i << "] = " << value << std::endl;
        i++;
    }
    std::cout << std::endl;
}

void exp_double_vector(std::vector<double> &vec)
{
    for (auto &value : vec)
    {
        value = std::exp(value);
    }
}

void log_double_vector(std::vector<double> &vec)
{
    for (auto &value : vec)
    {
        value = std::log(value);
    }
}

// Exercise:
// Implementiere die bestehenden Funktionen mit einer for-each for-Schleife
int main()
{
    std::vector<double> my_vector(3, 0.0);

    fill_double_vector(my_vector);
    print_double_vector(my_vector);

    exp_double_vector(my_vector);
    print_double_vector(my_vector);

    log_double_vector(my_vector);
    print_double_vector(my_vector);

    return 0;
}
