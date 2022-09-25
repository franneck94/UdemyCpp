#include <iostream>

int main()
{
    // 0=mon, 1=tues, 2=wed, ...
    // 5=sat, 6=sun
    int day = 5;

    if (day == 0 || day == 1 || day == 2 || day == 3 || day == 4)
    {
        std::cout << "It is a weekday!" << std::endl;
    }
    else
    {
        std::cout << "It is weekend!" << std::endl;
    }

    return 0;
}
