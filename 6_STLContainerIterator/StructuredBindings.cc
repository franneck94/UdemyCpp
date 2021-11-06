#include <iostream>
#include <map>
#include <string>
#include <tuple>

std::tuple<int, std::string, double> get_data()
{
    return std ::make_tuple(1337, "data", 1337.0);
}

int main()
{
    std::map<int, std::string> m;

    const auto [it, inserted] = m.insert({1, "one"});
    std::cout << "inserted = " << inserted << '\n' << "value = " << it->second << '\n';

    const auto &[id, name, score] = get_data();
    // id = 2;
    std::cout << id << std::endl;
}
