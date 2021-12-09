#include <cstdlib>
#include <iostream>

// Argc: Argument Count
// Argv: Argument Values
int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }

    if (argc > 1)
    {
        const char *arg1 = argv[1];
        std::cout << arg1 << std::endl;

        int arg2 = std::atoi(argv[2]);
        std::cout << arg2 << std::endl;
    }

    return 0;
}
