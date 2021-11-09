#include <cstdlib>
#include <iostream>
#include <sstream>

// Argc: Argument Count
// Argv: Argument Values (array of char arrays)
int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }

    if (argc > 1)
    {
        std::string arg1 = argv[1];
        std::cout << arg1 << std::endl;

        int arg2 = std::atoi(argv[2]);
        std::cout << arg2 << std::endl;
    }
    else
    {
        std::cout << "No arguments passed.\n";
    }

    return 0;
}
