#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> my_vector(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);
    std::vector<int> my_result(10, 0);
    std::vector<int> my_result2;

    // REMOVE IF: Lösche den Wert aus my_vector, wenn dieser größer als 5 ist.
    // WICHTIG: Löscht den Wert bei return true!
    my_vector.erase(std::remove_if(my_vector.begin(), my_vector.end(),
        [](int val) -> int
        {
            if (val > 5)
                return true;
            else
                return false;
        }
    ),
        my_vector.end());
    for (const auto &val : my_vector)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;

    // REMOVE IF: Lösche den Wert aus my_vector, wenn dieser größer als 3 ist.
    // WICHTIG: Löscht den Wert bei return true!
    int upper_bound = 3;

    my_vector.erase(std::remove_if(my_vector.begin(), my_vector.end(),
        [&upper_bound](const int &val) -> int
        {
            if (val > upper_bound)
                return true;
            else
                return false;
        }
    ),
        my_vector.end());
    for (const auto &val : my_vector)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;

    return 0;
}