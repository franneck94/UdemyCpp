#include <iostream>

int modulo(int n1, int n2)
{
    int result_integer_division = n1 / n2;
    int remainder = n1 - (n2 * result_integer_division);

    return remainder;
}

int main()
{
    int a = 1337;
    int b = 17;

    std::cout << modulo(a, b) << std::endl;
    std::cout << a % b << std::endl;

    return 0;
}
