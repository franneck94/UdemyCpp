#include <chrono>
#include <iostream>
#include <tuple>

auto get_yyyy_mm_dd(std::chrono::system_clock::time_point tp)
{
    auto ymd =
        std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(tp));
    auto y = static_cast<std::int32_t>(ymd.year());
    auto m = static_cast<std::uint32_t>(ymd.month());
    auto d = static_cast<std::uint32_t>(ymd.day());

    return std::make_tuple(y, m, d);
}

int main()
{
    // auto time = std::uint64_t{1669185762};
    auto time = std::time(nullptr);
    auto sysTime = std::chrono::system_clock::from_time_t(time);

    const auto [yyyy, mm, dd] = get_yyyy_mm_dd(sysTime);
    std::cout << "Current Year: " << yyyy << ", Month: " << mm
              << ", Day: " << dd << '\n';

    return 0;
}
