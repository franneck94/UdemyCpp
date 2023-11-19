#include <iostream>
#include <string>

template <typename T>
T concat(T first)
{
    return first;
}

template <typename T, typename... Args>
T concat(T first, Args... args)
{
    return first + concat(args...);
}

int main()
{
    const auto s1 = std::string{"Ha"};
    const auto s2 = std::string{"ll"};
    const auto s3 = std::string{"o"};

    // first=s1, ...args=[s2, s3]
    // first=s2, ...args=[s3]
    // first=s3, ...args=[]
    std::cout << concat(s1, s2, s3) << '\n';

    std::cout << concat(2, 3, 4) << '\n';

    return 0;
}
