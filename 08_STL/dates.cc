#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

int main()
{
    std::chrono::weekday wd = std::chrono::Thursday + std::chrono::days{4};
    std::cout << wd << '\n';

    auto ymd = std::chrono::year_month_day{1994y, std::chrono::February, 2d};
    std::cout << ymd << '\n';

    // format: year / month /day
    auto d1 = 2020y / 1 / 15;
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
