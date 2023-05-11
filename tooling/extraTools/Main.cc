#include <cstdint>
#include <iostream>

int main()
{
    const auto length = std::size_t{4};
    auto arr = new std::int32_t[length];

    if (!arr)
    {
        return 1;
    }

    for (std::size_t i = 0; i < length; i++)
    {
        arr[i] = static_cast<std::int32_t>(i);
        std::cout << arr[i] << '\n';
    }

    delete[] arr;
}
