#include <iostream>

int main()
{
    // 1.0, 2.0, 0, 0, 0, 0, 0, 0, 0, 0
    int user_balances[10] = {};

    for (int i = 0; i < 10; i++)
    {
        std::cout << user_balances[i] << std::endl;
    }

    return 0;
}