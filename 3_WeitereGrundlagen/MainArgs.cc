#include <iostream>
#include <sstream>

// Argc: Argument Count
// Argv: Argument Values (array of char arrays)
int main(int argc, char **argv)
{
    std::cout << "Argument count: " << argc << std::endl;

    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }

    if (argc > 1)
    {
        std::stringstream sstrValue;
        sstrValue << argv[1];

        int my_int_argument = 0;
        sstrValue >> my_int_argument;

        std::cout << my_int_argument * 2 << std::endl;
    }

    return 0;
}
