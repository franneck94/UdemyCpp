#include <iostream>
#include <vector>

struct PlayerData
{
    float x;
    float y;
};

// typedef std::vector<PlayerData> PlayerDataVector;
using PlayerDataVector = std::vector<PlayerData>;

int main()
{
    auto vec = PlayerDataVector{PlayerData{1.0F, 2.0F}, PlayerData{4.0F, 6.0F}};

    for (auto [x_, y_] : vec)
    {
        x_ = -1.0F;
        std::cout << x_ << " " << y_ << std::endl;
    }

    for (auto &[x_, y_] : vec)
    {
        std::cout << x_ << " " << y_ << std::endl;
    }

    return 0;
}
