#include <iostream>
#include <map>
#include <string>
#include <tuple>

void get_data_old(int &a, std::string &b, double &c)
{
    a = 1337;
    b = "data";
    c = 1337.0;
}

std::tuple<int, std::string, double> get_data()
{
    return std::make_tuple(1337, "data", 1337.0);
}

int main()
{
    int a = 0;
    std::string b = "";
    double c = 0.0;

    get_data_old(a, b, c);
    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';

    const auto [id, name, score] = get_data();
    std::cout << id << '\n';
    std::cout << name << '\n';
    std::cout << score << '\n';
}
