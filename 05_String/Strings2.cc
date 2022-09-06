#include <fstream>
#include <iostream>
#include <string>

void print_found_idx(const std::size_t idx, const std::string &func_name)
{
    std::cout << "Function: " << func_name << '\n';
    if (idx != std::string::npos)
        std::cout << "Found at idx: " << idx << "!\n\n";
    else
        std::cout << "Not Found!\n\n";
}

int main()
{
    const auto text = std::string{"Eines\nZwei\nDrei\n"};
    std::cout << text << '\n';

    const auto search_str = "drei";
    const auto idx = text.find(search_str);
    print_found_idx(idx, "find");

    const auto text2 = std::string{"abab"};
    const auto search_str2 = "ab";

    const auto idx2 = text2.find(search_str2);
    print_found_idx(idx2, "find");

    const auto idx3 = text2.rfind(search_str2);
    print_found_idx(idx3, "rfind");

    const auto idx4 = text2.find_first_not_of(search_str2);
    print_found_idx(idx4, "find_first_not_of");

    const auto idx5 = text2.find_last_not_of(search_str2);
    print_found_idx(idx5, "find_last_not_of");

    const auto idx6 = text2.find_first_of(search_str2);
    print_found_idx(idx6, "find_first_of");

    const auto idx7 = text2.find_last_of(search_str2);
    print_found_idx(idx7, "find_last_of");

    return 0;
}
