#include <fstream>
#include <iostream>
#include <optional>
#include <string>


std::optional<std::string> readFile(const std::string &file_path)
{
    std::ifstream iffile(file_path);

    if (iffile)
    {
        std::string data;

        while (getline(iffile, data))
        {
            iffile >> data;
        }

        iffile.close();
        return data;
    }

    return {};
}

int main()
{
    std::optional<std::string> file_content = readFile("text2.txt");

    if (file_content.has_value())
    {
        std::cout << file_content.value() << std::endl;
    }
    else
    {
        std::cout << "Could not open file!" << std::endl;
    }

    return 0;
}