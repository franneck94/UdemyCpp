#include <iostream>
#include <vector>

struct Data
{
    float x;
    float y;
};

int main()
{
    auto vec = std::vector<Data>{Data{1.0F, 2.0F}, Data{4.0F, 6.0F}};

    for (auto [x_, y_] : vec)
    {
        x_ = -1.0F;
        std::cout << x_ << " " << y_ << '\n';
    }

    for (auto &[x_, y_] : vec)
    {
        std::cout << x_ << " " << y_ << '\n';
    }

    return 0;
}
