#include <fstream>
#include <iostream>

#include "json.hpp"

int main()
{
    auto ifs = std::ifstream{"c_cpp_properties.json"};
    auto data = nlohmann::json{};
    ifs >> data;

    std::cout << data["configurations"][0]["name"] << '\n';
    std::cout << data["configurations"][0]["compilerPath"] << '\n';
    std::cout << data["configurations"][0]["cStandard"] << '\n';
    std::cout << data["configurations"][0]["cppStandard"] << '\n';

    data["configurations"][0]["cppStandard"] = "c++23";

    auto ofs = std::ofstream{"c_cpp_properties_edited.json"};
    ofs << std::setw(4) << data;

    return 0;
}
