#include <iostream>
#include <map>
#include <vector>

template <typename T>
using UserData = std::map<int, std::vector<T>>;

int main()
{
    UserData<double> my_double_data;
    UserData<float> my_float_data;

    return 0;
}
