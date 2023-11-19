#include <iostream>
#include <vector>

struct PlayerData
{
    float x;
    float y;
};

// AllPlayerData

// C-Approach
// typedef std::vector<PlayerData> AllPlayerData;

// C++-Approach
using AllPlayerData = std::vector<PlayerData>;

int main()
{
    auto vec = AllPlayerData{PlayerData{1.0F, 2.0F}, PlayerData{4.0F, 6.0F}};

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
