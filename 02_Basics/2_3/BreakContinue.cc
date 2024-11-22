#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t sum = 0;

    do
    {
        std::cout << "\nCurrent sum: " << sum << " Enter the next value: ";
        std::int32_t input = 0;
        std::cin >> input;

        if (input < 0)
        {
            std::cout << "Canceled while loop!" << std::endl;
            break;    // beendet die komplette schleife
            continue; // beendet aktuellen durchlauf
        }

        sum += input;
    } while (true); // unendliche schleife

    return 0;
}
