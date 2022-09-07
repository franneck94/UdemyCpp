#include <iostream>
#include <string>

int main()
{
    const auto text = std::string{"Eins, Zwei, Drei"};

    auto text2 = text;
    std::cout << "text2: " << text2 << '\n';
    text2.clear();
    std::cout << "text2: " << text2 << '\n';

    auto text3 = text + ", Vier";
    std::cout << "text3: " << text3 << '\n';

    auto text4 = text3;
    text4.append({' ', ',', 'F', 'u', 'e', 'n', 'f'});
    std::cout << "text4: " << text4 << '\n';

    auto s1 = std::string{"Jann"};
    auto s2 = std::string{"Jan"};
    std::cout << "s1 == s2: " << std::boolalpha << (s1 == s2) << '\n';
    const auto comapared = s1.compare(s2);
    std::cout << "s1.comapre(s2): " << comapared << '\n';

    const auto search_str = "nn";
    const auto idx = s1.find(search_str);
    if (idx != std::string::npos)
        s1.replace(idx, 2, "n");

    const auto sub_str = s1.substr(2, 3);
    std::cout << sub_str << '\n';

    return 0;
}
