#include <iostream>
#include <thread>

void function()
{
    const auto thread_id = std::this_thread::get_id();
    std::cout << "Thread ID: " << thread_id << '\n';

    std::cout << "Working\n";
}

int main()
{
    const auto main_id = std::this_thread::get_id();
    std::cout << "Main Thread ID: " << main_id << '\n';

    auto t1 = std::thread(function);

    if (t1.joinable())
    {
        t1.join();
    }

    return 0;
}
