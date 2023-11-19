#include <iostream>

void print_int_pointer(int *p)
{
    std::cout << "Dref: " << *p << " Ref: " << p << '\n';
}

int main()
{
    int a = 1337;

    int *c = &a;
    print_int_pointer(c);

    *c -= 10;
    print_int_pointer(c);

    int *d = &a;
    print_int_pointer(d);

    *c += 10;
    print_int_pointer(d);

    return 0;
}
