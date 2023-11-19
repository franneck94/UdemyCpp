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
    auto time1 = std::uint64_t{1669185762};
    auto sys_time1 = std::chrono::system_clock::from_time_t(time1);
    const auto [yyyy1, mm1, dd1] = get_yyyy_mm_dd(sys_time1);
    std::cout << "Current Year: " << yyyy1 << ", Month: " << mm1
              << ", Day: " << dd1 << '\n';

    auto time2 =
        std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
    auto sys_time2 = time2;
    const auto [yyyy2, mm2, dd2] = get_yyyy_mm_dd(sys_time2);
    std::cout << "Current Year: " << yyyy2 << ", Month: " << mm2
              << ", Day: " << dd2 << '\n';

    return 0;
}
