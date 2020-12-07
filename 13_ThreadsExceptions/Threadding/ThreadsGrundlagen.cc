#include <iostream>
#include <thread>

void print_text1()
{
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << std::endl;
}

void print_text2(int number)
{
    number++;
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << " n: " << number << std::endl;
}

void print_text3(int &number)
{
    number++;
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << " n: " << number << std::endl;
}

int main()
{
    std::thread t1(print_text1);

    if (t1.joinable())
    {
        t1.join();
    }

    int n = 0;
    std::thread t2(print_text2, n);

    if (t2.joinable())
    {
        t2.join();
    }
    std::cout << n << std::endl;

    int m = 0;
    std::thread t3(print_text3, std::ref(m));

    if (t3.joinable())
    {
        t3.join();
    }
    std::cout << m << std::endl;

    return 0;
}