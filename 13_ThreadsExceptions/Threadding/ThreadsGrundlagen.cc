#include <iostream>
#include <thread>

void print_text()
{
    std::cout << "Thread executed!\n";
}

void print_text2(int number)
{
    std::cout << "Thread executed!\n";
    number++;
}

void print_text3(int &number)
{
    std::cout << "Thread executed!\n";
    number++;
}

int main()
{
    // Thread erstellen
    std::thread t1(print_text);
    std::thread t2(print_text);

    // Join
    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();

    // Detach
    // t1.detach();
    // t2.detach();

    // Funktionen übergeben
    int n1 = 12;
    int n2 = 24;

    std::thread t3(print_text2, n1);
    std::thread t4(print_text2, n2);

    if (t3.joinable())
        t3.join();
    if (t4.joinable())
        t4.join();

    std::cout << std::endl << "n1: " << n1 << "\n";
    std::cout << std::endl << "n2: " << n2 << "\n";

    // Referenzen übergeben
    n1 = 12;
    n2 = 24;

    t3 = std::thread(print_text3, std::ref(n1));
    t4 = std::thread(print_text3, std::ref(n2));

    if (t3.joinable())
        t3.join();
    if (t4.joinable())
        t4.join();

    std::cout << std::endl << "n1: " << n1 << "\n";
    std::cout << std::endl << "n2: " << n2 << "\n";

    // Anzahl an Threads bestimmen
    unsigned int possible_threads = std::thread::hardware_concurrency();
    std::cout << std::endl << "Poss. Threads: " << possible_threads;

    // Thread ID
    std::thread::id main_thread_id = std::this_thread::get_id();
    std::cout << std::endl << "Thread ID of main: " << main_thread_id;

    return 0;
}