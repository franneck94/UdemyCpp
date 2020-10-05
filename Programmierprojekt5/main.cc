#include <type_traits>
#include <iostream>

int main()
{
    using T1 = int;
    using T2 = double;
    using U1 = short;
    using U2 = float;

    std::cout << std::conjunction_v<
            std::is_constructible<T1, const U1&>,
            std::is_constructible<T2, const U2&>> << std::endl;

    std::cout << std::is_constructible_v<T1, U1> << " <=> " << std::is_constructible_v<U1, T1> << std::endl;

    using U3 = unsigned char;

    std::cout << std::is_constructible_v<T1, U3> << " <=> " << std::is_constructible_v<U3, T1> << std::endl;

}