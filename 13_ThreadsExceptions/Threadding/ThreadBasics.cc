#include <iostream>
#include <thread>

void function()
{
    auto id = std::this_thread::get_id();

    std::cout << "ID from *function*: " << id << '\n';
}

int main()
{
    auto id = std::this_thread::get_id();
    std::cout << "ID from *main*: " << id << '\n';

    std::thread t1(function);

    // ...

    if (t1.joinable())
    {
        t1.join();
    }

    return 0;
}
