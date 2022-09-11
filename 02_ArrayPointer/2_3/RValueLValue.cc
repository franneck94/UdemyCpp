#include <iostream>

// LValue: Left
// RValue: Right

void copy_by_value(int v)
{
    std::cout << v << std::endl;
}

void copy_by_value_const(const int v)
{
    std::cout << v << std::endl;
}

void reference(int &v)
{
    std::cout << v << std::endl;
}

void reference_const(const int &v)
{
    std::cout << v << std::endl;
}

int main()
{
    int lvalue = 2;
    const int lvalue_const = 2;

    copy_by_value(lvalue);
    copy_by_value(lvalue_const);
    copy_by_value(2);

    copy_by_value_const(lvalue);
    copy_by_value_const(lvalue_const);
    copy_by_value_const(2);

    reference(lvalue);
    // reference(lvalue_const);
    // reference(2);

    reference_const(lvalue);
    reference_const(lvalue_const);
    reference_const(2);

    return 0;
}
