#include <iostream>
#include <string>
#include <string_view>

void *operator new(std::size_t count)
{
    std::cout << "allocating" << std::endl;
    return malloc(count);
}

void do_something1(const std::string &s)
{
    std::cout << s << std::endl;
}

void do_something2(std::string_view sv)
{
    std::cout << sv << std::endl;
}

int main()
{
    std::string s("Hi, my name is Jan and i am your instructor.");

    std::string sub_s(s.substr(4, 32));
    do_something1(sub_s);

    do_something1("Hi, my name is Jan and i am your instructor.");
    do_something2("Hi, my name is Jan and i am your instructor.");

    return 0;
}
