#include <iostream>
#include <map>
#include <vector>

// using ui32 = unsigned int;
// template <typename T>
// typedef std::map<int, std::vector<T>> MapData;
template <typename T>
using MapData = std::map<int, std::vector<T>>;

int main()
{
    MapData<double> my_accounts;

    return 0;
}
