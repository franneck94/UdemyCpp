#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

unsigned int alloc_count = 0;

void *operator new(std::size_t n)
{
    alloc_count++;
    std::cout << "I am allocating on the heap: " << n << std::endl;

    return malloc(n);
}

void do_something1(const std::string &s)
{
    std::cout << s << std::endl;
}

void do_something2(const std::string_view &sv)
{
    std::cout << sv << std::endl;
}

int main()
{
    std::string s(
        "Ich heisse Jan Schaffranek und bin Dozent auf der Plattform Udemy.");

    std::string sub_s(s.substr(4, 16));
    do_something1(sub_s);
    std::cout << alloc_count << std::endl;

    std::string_view view_s(s.c_str() + 4, 16);
    do_something2(view_s);
    std::cout << alloc_count << std::endl;

    return 0;
}
