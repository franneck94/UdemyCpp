#include <exception>
#include <iostream>
#include <string>
#include <string_view>

class DivisionByZero : public std::exception
{
public:
    DivisionByZero(std::string_view _message) : message(_message){};

    std::string message;

    [[nodiscard]] const char *what() const noexcept override
    {
        return message.c_str();
    }
};

double div(double x, double y)
{
    if (y == 0.0)
    {
        throw DivisionByZero("DivisionByZero 1");
        // throw std::invalid_argument("DivisionByZero 2");
    }

    return x / y;
}

int main()
{
    try
    {
        div(1.0, 0.0);
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << '\n';
    }

    return 0;
}
