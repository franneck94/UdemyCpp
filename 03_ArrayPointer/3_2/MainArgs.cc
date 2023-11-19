#include <cstdlib>
#include <iostream>

// argc: argument count
// argv: argument values
int main(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << '\n';
    }

    if (argc > 1)
    {
        int arg_value = std::atoi(argv[1]);
        std::cout << arg_value << '\n';
    }

    return 0;
}
