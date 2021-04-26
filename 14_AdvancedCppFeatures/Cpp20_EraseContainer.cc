#include <iostream>
#include <numeric>
#include <string_view>
#include <vector>

void print_container(std::string_view comment, const std::vector<char> &c)
{
    std::cout << comment;
    std::cout << "Length: " << c.size() << '\n';
    for (auto x : c)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<char> cnt(10);
    std::iota(cnt.begin(), cnt.end(), '0');
    print_container("Init:\n", cnt);

    std::erase(cnt, '3');
    print_container("Erase '3':\n", cnt);

    auto erased = std::erase_if(cnt, [](char x) { return (x - '0') % 2 == 0; });
    print_container("Erase all even numbers:\n", cnt);
    std::cout << "In all " << erased << " even numbers were erased.\n";
}
