#include <iostream>

[[nodiscard]] int get_value1()
{
    return 1;
}

enum class [[nodiscard]] ReturnCodes
{
    OK,
    NoData,
    Error
};

struct [[nodiscard]] Item
{
};

[[deprecated("Func1 is deprecated consider using func2()")]] void func1()
{
}

[[maybe_unused]] double run(double d)
{
    return 2.0 * d;
}

int main()
{
    get_value1();
    func1();
    run(11.0);

    int alternative = get_value1();
    switch (alternative)
    {
    [[likely]] case 1:
        [[fallthrough]];
    [[likely]] case 2:
    {
        std::cout << "Case 1 and 2\n";
        break;
    }
        [[unlikely]] default : std::cout << "Default\n";
    }

    return 0;
}
