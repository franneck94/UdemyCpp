#include <iostream>

bool is_even(int number)
{
    if (number % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int my_number = 3;
    bool check = is_even(my_number);

    return 0;
}
