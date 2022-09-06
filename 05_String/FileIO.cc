#include <fstream>
#include <iostream>
#include <string>

int main()
{
    auto str = std::string{};
    auto text = std::string{};

    /*********/
    /* READ  */
    /*********/
    auto iffile = std::ifstream{};
    iffile.open("TextInput.txt");
    if (iffile.is_open())
    {
        while (std::getline(iffile, str))
        {
            text += str + '\n';
        }
    }
    iffile.close();

    std::cout << text << '\n';

    const auto search_str = std::string{"eins"};
    const auto replace_str = std::string{"one"};
    const auto idx = text.find(search_str);
    if (idx != std::string::npos)
        text.replace(idx, search_str.size(), replace_str);

    /*********/
    /* WRITE */
    /*********/
    auto offile = std::ofstream{};
    offile.open("TextOutput.txt");
    if (offile.is_open())
    {
        offile << text;
    }
    offile.close();

    return 0;
}
