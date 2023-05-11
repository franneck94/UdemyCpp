#include <cstdint>
#include <iostream>

// Output the length of the char array (String)
// The '\0' is not included in the length value

int main()
{
    char array1[] = {'A', 'B', 'C', '\0'};

    std::uint32_t len = 0;
    while (true)
    {
        if (array1[len] != '\0')
            ++len;
        else
            break;
    }

    std::cout << "Length: " << len << '\n';

    return 0;
}
