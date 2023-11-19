#include <array>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

// template <typename T>
// void print_container(const std::vector<T> &vec)
// {
//     for (const auto val : vec)
//     {
//         std::cout << val << '\n';
//     }
// }

// template <typename T, std::size_t N>
// void print_container(const std::array<T, N> &arr)
// {
//     for (const auto val : arr)
//     {
//         std::cout << val << '\n';
//     }
// }

template <typename T>
void print_container(std::span<const T> span)
{
    for (const auto val : span)
    {
        std::cout << val << '\n';
    }
}

int main()
{
    std::int32_t my_c_arr[] = {1, 2, 3, 4, 5};
    auto my_vec = std::vector<std::int32_t>{1, 2, 3, 4, 5};
    auto my_arr = std::array<std::int32_t, 5U>{1, 2, 3, 4, 5};

    print_container<std::int32_t>(my_vec);
    std::cout << '\n';
    print_container<std::int32_t>(my_arr);
    std::cout << '\n';
    print_container<std::int32_t>(my_c_arr);
    std::cout << '\n';

    auto vec_span = std::span{my_vec};
    auto sspan = vec_span.subspan(1, 2);
    print_container<std::int32_t>(sspan);
    std::cout << '\n';

    return 0;
}
