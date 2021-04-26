#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string str;
    std::string text;

    std::ifstream iffile;
    iffile.open("Text.txt");

    if (iffile.is_open())
    {
        while (std::getline(iffile, str))
        {
            text += str + "\n";
        }

        std::cout << text << std::endl;
    }

    iffile.close();

    // Wir suchen nach dem Wort "eins"
    int index = text.find("eins");
    text.replace(index, 4, "one");

    std::cout << text << std::endl;

    std::ofstream offile;
    offile.open("TextOutput.txt");

    offile << text;
    offile.close();

    return 0;
}
