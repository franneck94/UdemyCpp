#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<int, std::string> m;

    auto [it, inserted] = m.insert({ 1, "one" });
    std::cout << "inserted = " << inserted << '\n'
        << "value = " << it->second << '\n';
}