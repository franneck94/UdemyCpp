#include <cstdint>
#include <iostream>

/**
 * @brief Computes max of a and b
 *
 * @tparam T Should be int or double only!
 * @param a
 * @param b
 * @return
 */
template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    double da = 1.0;
    double db = 3.0;
    std::cout << max<double>(da, db) << '\n';

    std::int32_t ia = 1;
    std::int32_t ib = 3;
    std::cout << max<double>(ia, ib) << '\n';

    char ca = 'a';
    char cb = 'b';
    std::cout << max(ca, cb) << '\n';

    return 0;
}
