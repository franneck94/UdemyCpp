#include <fstream>
#include <iostream>

#include "json.hpp"

int main()
{
    std::ifstream ifs("c_cpp_properties.json");
    nlohmann::json data;
    ifs >> data;

    std::cout << data["configurations"][0]["compilerPath"] << std::endl;
    std::cout << data["configurations"][0]["intelliSenseMode"] << std::endl;

    data["configurations"][0]["cppStandard"] = "c++11";

    std::ofstream ofs("c_cpp_properties_edited.json");
    ofs << std::setw(4) << data;

    return 0;
}
