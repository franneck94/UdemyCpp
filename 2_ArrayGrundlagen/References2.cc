#include <iostream>

// CallByValue
void f1(int number)
{
    number++;
}

// CallByReference
void f2(int &number)
{
    number++;
}

int f3(int number)
{
    return number + 1;
}

int main()
{
    int num = 5;
    std::cout << num << std::endl;
    f1(num);
    std::cout << num << std::endl;
    f2(num);
    std::cout << num << std::endl;
    num = f3(num);
    std::cout << num << std::endl;

    return 0;
}