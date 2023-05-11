#include <cstdint>
#include <iostream>
#include <thread>

void function1()
{
    const auto thread_id = std::this_thread::get_id();
    std::cout << "Thread ID: " << thread_id << '\n';
}

void function2(std::int32_t number)
{
    const auto thread_id = std::this_thread::get_id();
    std::cout << "Thread ID: " << thread_id << '\n';
    std::cout << "number: " << number << '\n';
}

void function3(std::int32_t &number)
{
    const auto thread_id = std::this_thread::get_id();
    std::cout << "Thread ID: " << thread_id << '\n';
    std::cout << "number: " << number << '\n';
}

int main()
{
    const auto main_id = std::this_thread::get_id();
    std::cout << "Main Thread ID: " << main_id << '\n';

    std::int32_t number = 42;

    auto t1 = std::thread(function1);
    auto t2 = std::thread(function2, number);
    auto t3 = std::thread(function3, std::ref(number));

    if (t1.joinable())
    {
        t1.join();
    }
    if (t2.joinable())
    {
        t2.join();
    }
    if (t3.joinable())
    {
        t3.join();
    }

    return 0;
}
