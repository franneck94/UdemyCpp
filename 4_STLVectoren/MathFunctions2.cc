#include <cmath>
#include <iostream>
#include <vector>


void fill_double_vector(std::vector<double> &vec)
{
    for (unsigned int i = 0; i < vec.size(); ++i)
    {
        vec[i] = i;
    }
}

void print_double_vector(const std::vector<double> &vec)
{
    for (unsigned int i = 0; i < vec.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << std::endl;
    }

    std::cout << std::endl;
}

void double_vector_exp(std::vector<double> &vec)
{
    for (unsigned int i = 0; i < vec.size(); ++i)
    {
        vec[i] = std::exp(vec[i]);
    }
}

void double_vector_exp_iterator(std::vector<double> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        *it = std::exp(*it);
    }
}

void double_vector_exp_for_each(std::vector<double> &vec)
{
    for (auto &vector_val : vec)
    {
        vector_val = std::exp(vector_val);
    }
}

void double_vector_log(std::vector<double> &vec)
{
    for (unsigned int i = 0; i < vec.size(); ++i)
    {
        vec[i] = std::log(vec[i]);
    }
}

void double_vector_log_iterator(std::vector<double> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        *it = std::log(*it);
    }
}

void double_vector_log_for_each(std::vector<double> &vec)
{
    for (auto &vector_val : vec)
    {
        vector_val = std::log(vector_val);
    }
}

int main()
{
    // Exercise:
    // 1.) Implementiere die bestehenden Funktionen mit einer for-Schleife, die einen
    // Iterator verwendet
    // 2.) Implementiere die bestehenden Funktionen mit einer for-each for-Schleife

    //                            LENGTH, DEFAULT VALUE
    std::vector<double> my_vector(4, 0); // [0.0, 0.0, 0.0 ,0.0]

    fill_double_vector(my_vector); // [0.0, 1.0, 2.0, 3.0]
    print_double_vector(my_vector);

    double_vector_exp_iterator(my_vector); // [exp(...), exp(...), ...]
    print_double_vector(my_vector);

    double_vector_log_iterator(
        my_vector); // log(exp(val) = val   [log(...), log(...), ...]
    print_double_vector(my_vector); // same output as in line 59

    double_vector_exp_for_each(my_vector); // [exp(...), exp(...), ...]
    print_double_vector(my_vector);

    double_vector_log_for_each(
        my_vector); // log(exp(val) = val   [log(...), log(...), ...]
    print_double_vector(my_vector); // same output as in line 59

    return 0;
}
