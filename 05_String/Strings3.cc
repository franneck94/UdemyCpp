#include <fstream>
#include <iostream>
#include <string>
int main()
{
    const auto text = std::string{"Eines\nZwei\nDrei\n"};
    std::cout << text << '\n';

    /*
    Operations:
        clear
        append, +=, +
        compare, ==
        replace
        substr
    */

    auto text_copy = text; // copy
    std::cout << "Content: " << text_copy << '\n';
    text_copy.clear();
    std::cout << "Content: " << text_copy << '\n';

    auto text_append = text + "vier\n";
    std::cout << "Content: " << text_append << '\n';
    text_append.append("fuenf\n");
    std::cout << "Content: " << text_append << '\n';

    auto s1 = std::string{"Jann"};
    const auto s2 = std::string{"Jann"};
    const auto compare = s1.compare(s2);
    std::cout << "compare: " << compare << '\n';
    std::cout << "equal: " << (s1 == s2) << '\n';

    auto search_str = std::string{"nn"};
    const auto idx = s1.find(search_str);
    s1.replace(idx, search_str.size(), "n");
    std::cout << "Content: " << s1 << '\n';

    const auto sub_str = s1.substr(0, 2);
    std::cout << "Content: " << sub_str << '\n';

    return 0;
}
