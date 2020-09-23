#include <iostream>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        std::cout << std::endl
                  << "Argc: <<<<<" << argc;

        for (int i = 0; i < argc; i++)
        {
            std::cout << std::endl
                      << argv[i];
        }

        char input1 = *argv[1];
        int input2 = atoi(argv[2]);
        bool input3 = atoi(argv[3]);

        std::cout << std::endl;

        std::cout << std::endl
                  << input1;
        std::cout << std::endl
                  << input2;
        std::cout << std::endl
                  << input3;
    }

    return 0;
}