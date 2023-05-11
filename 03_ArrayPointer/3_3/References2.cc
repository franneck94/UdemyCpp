#include <iostream>

void copy(int v) // copy - Input but modifiable
{
    v *= 2;
    std::cout << "f1: " << v << '\n';
    std::cout << &v << '\n';
}

void copy_const(const int v) // const - Input only because of const
{
    std::cout << "f1: " << v << '\n';
    std::cout << &v << '\n';
}

void reference_input(const int &v) // Input only because of const
{
    std::cout << "f3: " << v << '\n';
    std::cout << &v << '\n';
}

void reference_in_output(int &v) // Input and Output
{
    v = v * 2; // In and Output
    v = 2;     // Output only
    std::cout << "f3: " << v << '\n';
    std::cout << &v << '\n';
}

int main()
{
    int a = 2;
    std::cout << a << '\n';
    std::cout << &a << '\n';

    copy(a);
    copy_const(a);
    reference_input(a);
    reference_in_output(a);

    std::cout << a << '\n';
    std::cout << &a << '\n';

    return 0;
}
