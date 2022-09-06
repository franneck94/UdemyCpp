#include <fstream>
#include <iostream>
#include <string>

struct PlayerData
{
    std::uint32_t id;
    float x_pos;
    float y_pos;
};

void print_player_pos(const PlayerData &player)
{
    std::cout << "Pos: (" << player.x_pos << ", " << player.y_pos << ")\n";
}

int append_line_to_file(const std::string &filepath, const std::string &line)
{
    auto file = std::ofstream{};

    file.open(filepath, std::ios::out | std::ios::app);
    if (file.fail())
        return 1;

    file << line << '\n';

    if (!file.good())
        return 1;

    return 0;
}

int write_to_bin_file(const std::string &filepath, const PlayerData &data)
{
    auto file = std::ofstream{};

    file.open(filepath, std::ios::out | std::ios::binary);
    if (file.fail())
        return 1;

    file.write((char *)&data, sizeof(PlayerData));

    if (!file.good())
        return 1;

    return 0;
}

int read_from_bin_file(const std::string &filepath, PlayerData &data)
{
    auto file = std::ifstream{};

    file.open(filepath, std::ios::in | std::ios::binary);
    if (file.fail())
        return 1;

    file.read((char *)&data, sizeof(PlayerData));

    if (!file.good())
        return 1;

    return 0;
}

int main()
{
    const auto text = std::string{"My sample text."};
    const auto filename1 = std::string{"text.txt"};
    append_line_to_file(filename1, text);

    const auto player = PlayerData{.id = 0, .x_pos = 10.0F, .y_pos = 110.0F};
    const auto filename2 = std::string{"text.bin"};
    write_to_bin_file(filename2, player);

    auto player2 = PlayerData{};
    read_from_bin_file(filename2, player2);
    print_player_pos(player2);

    return 0;
}
