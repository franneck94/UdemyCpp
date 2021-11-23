#include <iostream>

#include "cxxopts.hpp"

int main(int argc, char **argv)
{
    cxxopts::Options options("test", "A brief description");

    options.add_options()("b,bar", "Param bar", cxxopts::value<std::string>());
    options.add_options()("d,debug", "Enable debugging", cxxopts::value<bool>()->default_value("false"));
    options.add_options()("f,foo", "Param foo", cxxopts::value<int>()->default_value("10"));
    options.add_options()("h,help", "Print usage");

    auto result = options.parse(argc, argv);

    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    auto bar = result["bar"].as<std::string>();
    auto debug = result["debug"].as<bool>();
    auto foo = result["foo"].as<int>();

    std::cout << "bar count: " << result["bar"].count() << std::endl;
    std::cout << "debug count: " << result["debug"].count() << std::endl;
    std::cout << "foo count: " << result["foo"].count() << std::endl;

    std::cout << bar << std::endl;
    std::cout << debug << std::endl;
    std::cout << foo << std::endl;

    return 0;
}
