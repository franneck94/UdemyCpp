#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string> m;

    const auto [it, inserted] = m.insert({1, "one"});
    std::cout << "inserted = " << inserted << '\n' << "value = " << it->second << '\n';

    constexpr int array[2] = {1, 2};
    const auto [a0, a1] = array;

    std::cout << "a0 = " << a0 << " a1 = " << a1 << std::endl;
}
