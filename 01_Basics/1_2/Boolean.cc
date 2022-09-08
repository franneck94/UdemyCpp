#include <iostream>

// !true == false
// !false == true

int main()
{
    int number;
    std::cout << "Pleaser enter a number: ";
    std::cin >> number;

    bool check = (number >= 0 && number <= 10);
    std::cout << std::boolalpha << check << std::endl;

    bool check2 = !(number >= 0 && number <= 10);
    std::cout << std::boolalpha << check2 << std::endl;

    return 0;
}
