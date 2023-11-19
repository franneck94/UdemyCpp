#include <iostream>
#include <string>
#include <string_view>

void *operator new(std::size_t count)
{
    std::cout << "allocating" << '\n';
    return malloc(count);
}

void do_something1(const std::string &s)
{
    std::cout << s << '\n';
}

void do_something2(std::string_view sv)
{
    std::cout << sv << '\n';
}

int main()
{
    auto s = std::string("Hi, my name is Jan and i am your instructor.");

    auto sub_s = std::string(s.substr(4, 32));
    do_something1(sub_s);

    do_something1("Hi, my name is Jan and i am your instructor.");
    do_something2("Hi, my name is Jan and i am your instructor.");

    return 0;
}
