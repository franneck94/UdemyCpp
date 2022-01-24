#include <iostream>
#include <thread>

void print_text1()
{
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << std::endl;
}

int main()
{
    std::thread t1(print_text1);

    if (t1.joinable())
    {
        t1.join();
    }

    return 0;
}
