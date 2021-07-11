#include <fstream>
#include <iostream>
#include <string>

std::string read_text(const std::string &path)
{
    std::string str;
    std::string text;

    std::ifstream iffile;
    iffile.open(path);

    if (iffile.is_open())
    {
        while (std::getline(iffile, str))
        {
            text += str + "\n";
        }
    }

    iffile.close();
    return text;
}

void write_text(const std::string &path, const std::string &text)
{
    std::ofstream offile;
    offile.open(path);

    if (offile.is_open())
    {
        offile << text;
    }

    offile.close();
}

int main()
{
    /* eins\nzwei\ndrei */
    std::string text = read_text("Text.txt");
    std::cout << "Content: " << text << std::endl;

    /*
    Operations:
        clear
        append, +=, +
        compare, ==
        replace
        substr
    */

    std::string text_copy = text;
    std::cout << "Content: " << text_copy << std::endl;
    text_copy.clear();
    std::cout << "Content: " << text_copy << std::endl;

    std::string text_append = text + "vier\n";
    std::cout << "Content: " << text_append << std::endl;
    text_append.append("fuenf\n");
    std::cout << "Content: " << text_append << std::endl;

    std::string s1 = "Jann";
    std::string s2 = "Jann";
    auto compare = s1.compare(s2);
    std::cout << "compare: " << compare << std::endl;
    std::cout << "equal: " << (s1 == s2) << std::endl;

    std::string search_str = "nn";
    auto idx = s1.find(search_str);
    s1.replace(idx, search_str.size(), "n");
    std::cout << "Content: " << s1 << std::endl;

    std::string sub_str = s1.substr(0, 2);
    std::cout << "Content: " << sub_str << std::endl;

    return 0;
}
