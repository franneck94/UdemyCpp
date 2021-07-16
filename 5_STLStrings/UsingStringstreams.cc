#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string birthday;

    std::cout << "Please enter your birthday (DD.MM.YYYY): ";
    std::cin >> birthday;

    std::stringstream birthday_ss(birthday);
    unsigned int day = 0;
    unsigned int month = 0;
    unsigned int year = 0;
    char c = 0;

    birthday_ss >> day >> c >> month >> c >> year;

    std::cout << "Your birthday is: " << day << "." << month << "." << year << std::endl;

    return 0;
}
