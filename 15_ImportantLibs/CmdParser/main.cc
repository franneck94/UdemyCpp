#include <iostream>

#include "cxxopts.hpp"

constexpr int MAJOR_VERSION = 1;
constexpr int MINOR_VERSION = 0;
constexpr int PATCH_VERSION = 0;

int main(int argc, char **argv)
{
    cxxopts::Options options("Name", "Description");

    options.add_options()("v,version", "Print version");
    options.add_options()("h,help", "Print all commands");
    options.add_options()("n,name", "Your name", cxxopts::value<std::string>()->default_value("Jan"));

    auto result = options.parse(argc, argv);

    if (result.count("version"))
    {
        std::cout << MAJOR_VERSION << "." << MINOR_VERSION << "." << PATCH_VERSION << std::endl;
    }

    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
    }

    auto name = result["name"].as<std::string>();

    std::cout << name << std::endl;

    return 0;
}
