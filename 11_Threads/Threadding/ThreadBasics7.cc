#include <chrono>
#include <cstdint>
#include <iostream>
#include <thread>
#include <vector>

using namespace ::std::literals;

namespace
{
constexpr auto NUM_THREADS = std::uint32_t{1U};
}

void function(const std::stop_token stop_token, std::int32_t value)
{
    const auto thread_id = std::this_thread::get_id();
    const std::stop_callback callBack(stop_token, [thread_id] {
        std::cout << "Stop request for: " << thread_id << '\n';
    });

    while (!stop_token.stop_requested())
    {
        std::cout << value++ << ' ' << std::flush;
        std::this_thread::sleep_for(200ms);
    }
}

int main()
{
    std::vector<std::jthread> threads(NUM_THREADS);
    for (auto &thread : threads)
    {
        thread = std::jthread(function, 5);
    }

    std::this_thread::sleep_for(1s);

    std::cout << '\n';
    for (auto &thread : threads)
    {
        std::cout << "Requests stop for " << thread.get_id() << '\n';
        thread.request_stop();
    }

    std::cout << "Destructor starts\n";
}
