#include <future>
#include <iostream>
#include <thread>

int print_text1()
{
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << std::endl;
    return 0;
}

int print_text2(int number)
{
    number++;
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << " n: " << number << std::endl;
    return 1;
}

int print_text3(int &number)
{
    number++;
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << " n: " << number << std::endl;
    return 2;
}

int main()
{
    auto handle1 = std::async(std::launch::async, print_text1);
    auto result1 = handle1.get();
    std::cout << "result1: " << result1 << std::endl;

    int n = 0;
    auto handle2 = std::async(std::launch::async, print_text2, n);
    auto result2 = handle2.get();
    std::cout << "result2: " << result2 << std::endl;
    std::cout << "n: " << n << std::endl;

    int m = 0;
    auto handle3 = std::async(std::launch::async, print_text3, std::ref(m));
    auto result3 = handle3.get();
    std::cout << "result3: " << result3 << std::endl;
    std::cout << "m: " << m << std::endl;

    return 0;
}
