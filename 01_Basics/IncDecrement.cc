
#include <iostream>

int main()
{
    for (int i = 2; i < 4; i += 1)
    {
        std::cout << i << std::endl;
    }

    // Increment i++ <=> i += 1 <=> i = i + 1
    // Decrement i-- <=> i -= 1 <=> i = i - 1

    for (int i = 2; i < 4; i++)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
