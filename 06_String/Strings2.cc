#include <iostream>
#include <string>

void print_found_idx(const std::size_t idx, const std::string &func_name)
{
    std::cout << "Function: " << func_name << '\n';
    if (idx != std::string::npos)
        std::cout << "Found at idx: " << idx << '\n';
    else
        std::cout << "Not Found!" << idx << '\n';
}

int main()
{
    const auto text = std::string{"Eins, Zwei, Drei"};

    const auto search_str1 = "i";
    const auto idx1 = text.find(search_str1, 5);
    print_found_idx(idx1, "find");

    const auto search_str2 = "i";
    const auto idx2 = text.rfind(search_str2);
    print_found_idx(idx2, "rfind");

    const auto search_str3 = "DZ";
    const auto idx3 = text.find_first_of(search_str3);
    print_found_idx(idx3, "find_first_of");

    const auto search_str4 = "DZ";
    const auto idx4 = text.find_last_of(search_str4);
    print_found_idx(idx4, "find_last_of");

    return 0;
}
