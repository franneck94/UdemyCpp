#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "json.hpp"

int main()
{
    std::ifstream ifs("c_cpp_properties.json");
    nlohmann::json data;
    ifs >> data;

    std::cout << data["configurations"][0]["name"] << std::endl;
    std::cout << data["configurations"][0]["includePath"] << std::endl;
    std::cout << data["configurations"][0]["compilerPath"] << std::endl;
    std::cout << data["configurations"][0]["cStandard"] << std::endl;
    std::cout << data["configurations"][0]["cppStandard"] << std::endl;
    std::cout << data["configurations"][0]["intelliSenseMode"] << std::endl;
    std::cout << data["configurations"][0]["compilerArgs"] << std::endl;

    const auto &include_path_data = data["configurations"][0]["includePath"];
    auto includes_path_vec = std::vector<std::string>(include_path_data.begin(), include_path_data.end());

    data["configurations"][0]["cppStandard"] = "c++11";

    std::ofstream ofs("c_cpp_properties_edited.json");
    ofs << std::setw(4) << data;

    return 0;
}
