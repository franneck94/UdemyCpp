#include <cmath>
#include <iostream>
#include <vector>

struct PlayerData
{
    float x;
    float y;
};

template <typename T>
void fill_vector(std::vector<T> &vec)
{
    for (int i = 0; auto &value : vec)
    {
        value = static_cast<T>(i);
        i++;
    }
}

template <typename T>
void print_vector(const std::vector<T> &vec)
{
    for (int i = 0; const auto &value : vec)
    {
        std::cout << "Vec[" << i << "] = " << value << '\n';
        i++;
    }
    std::cout << '\n';
}

int main()
{
    auto my_vector1 = std::vector<std::int32_t>(3, 0);
    auto my_vector2 = std::vector<float>(3, 0);
    auto my_vector3 = std::vector<char>(3, 97);

    print_vector(my_vector1);
    print_vector(my_vector2);
    print_vector(my_vector3);

    // auto my_vector4 =
    //     std::vector<PlayerData>{PlayerData{1.0F, 2.0F}, PlayerData{4.0F, 6.0F}};
    // print_vector(my_vector4);

    return 0;
}
