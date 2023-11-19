#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

int main()
{
    auto half_day = std::chrono::hours(12);
    auto minutes = std::chrono::minutes(60);
    auto seconds = std::chrono::seconds(30);
    auto milliseconds = std::chrono::milliseconds(500);
    auto microseconds = std::chrono::microseconds(500);
    auto nanoseconds = std::chrono::nanoseconds(500);

    // format: year / month /day
    auto d1 = 2023y / 1 / 15;
    auto d2 = 2020y / std::chrono::January / 15;
    // format: day / month / year
    auto d3 = 15d / 1 / 2020;
    auto d4 = 15d / std::chrono::January / 2020;
    // format: month / day / year
    auto d5 = 1 / 15d / 2020;
    auto d6 = std::chrono::January / 15 / 2020;

    auto time = std::chrono::zoned_time{std::chrono::current_zone(),
                                        std::chrono::system_clock::now()};
    std::cout << time << '\n';

    auto time2 = std::chrono::zoned_time{std::chrono::locate_zone("Asia/Tokyo"),
                                         std::chrono::system_clock::now()};
    std::cout << time2 << '\n';

    return 0;
}
