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
    std::string s1 = "Ha";
    std::string s2 = "ll";
    std::string s3 = "o";

    // first=s1, ...args=[s2, s3]
    // first=s2, ...args=[s3]
    // first=s3, ...args=[]
    std::cout << concat(s1, s2, s3) << std::endl;

    std::cout << concat(2, 3, 4) << std::endl;

    return 0;
}
