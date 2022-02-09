#include <iostream>

int main()
{
    auto i = 3.5;
    auto j = static_cast<int>(i);

    auto k = double{0.0F};
    auto l{0.0F};
    auto m{0};
    auto n{0U};
    auto o{0L};

    auto p = int{1};
    int q{1};

    std::cout << i << j << k << l << m << n << o << p << q << std::endl;

    return 0;
}
