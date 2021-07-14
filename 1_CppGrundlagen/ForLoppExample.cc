#include <iostream>

int main()
{
    double input_number;
    int num_iterations;

    std::cout << "Please enter a number: ";
    std::cin >> input_number;
    std::cout << std::endl;
    std::cout << "How many iterations? ";
    std::cin >> num_iterations;
    std::cout << std::endl;

    for (int i = 0; i < num_iterations; i++)
    {
        input_number = input_number * input_number;
        std::cout << "Iteration: " << i << " number: " << input_number
                  << std::endl;
    }

    return 0;
}
