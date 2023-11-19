#include <iostream>
#include <string>

template <typename T, typename... Args>
T concat(Args... args)
{
    return (... + args);
}

int main()
{
    const auto s1 = std::string{"Ha"};
    const auto s2 = std::string{"ll"};
    const auto s3 = std::string{"o"};

    std::cout << concat<std::string>(s1, s2, s3) << '\n';
    std::cout << concat<int>(1, 2, 3) << '\n';

    return 0;
}
