#include <iostream>
#include <thread>

void function1()
{
    auto id = std::this_thread::get_id();

    std::cout << "ID from *function*: " << id << '\n';
}

void function2(int number)
{
    number *= 2;

    std::cout << "Input to *function2* multiplied by 2: " << number << '\n';
}

void function3(int &number)
{
    number *= 2;

    std::cout << "Input to *function3* multiplied by 2: " << number << '\n';
}

int main()
{
    std::thread t1(function1);

    if (t1.joinable())
    {
        t1.join();
    }

    int number2 = 1;
    std::thread t2(function2, number2);

    if (t2.joinable())
    {
        t2.join();
    }

    std::cout << "number2 in main: " << number2 << '\n';

    int number3 = 1;
    std::thread t3(function3, std::ref(number3));

    if (t3.joinable())
    {
        t3.join();
    }

    std::cout << "number3 in main: " << number3 << '\n';

    return 0;
}
