#include <iostream>
#include <string>
#include <string_view>

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

    std::string sub_s(s.substr(4, 16));
    do_something1(sub_s);

    std::string_view view_s(s.c_str() + 4, 16);
    do_something2(view_s);

    return 0;
}
