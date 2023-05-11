#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

template <typename T>
class _lambda1
{
public:
    bool operator()(const T n) const
    {
        return n > 0;
    }
};
auto l = [](const auto n) { return n > 0; };

template <typename T>
class _lambda2
{
    int minimum_;
    int maximum_;

public:
    explicit _lambda2(const T minimum, const T maximum)
        : minimum_(minimum), maximum_(maximum)
    {
    }
    _lambda2(const _lambda2 &) = default;
    _lambda2(_lambda2 &&) = default;
    _lambda2 &operator=(const _lambda2 &) = delete;
    ~_lambda2() = default;
    bool operator()(const T n) const
    {
        return minimum_ <= n && n <= maximum_;
    }
};

template <typename T>
void print_vector(const std::vector<T> &vec)
{
    for (const auto &val : vec)
    {
        std::cout << val << '\n';
    }

    std::cout << '\n';
}

template <typename T>
bool check_even(const T value)
{
    return (value % 2) == 0;
}

int main()
{
    auto my_vector = std::vector<int>(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);
    print_vector(my_vector);

    for (const auto val : my_vector)
    {
        std::cout << std::boolalpha << check_even(val) << '\n';
    }
    std::cout << '\n';

    const auto N = 3;
    //                Cap. List, Param List, Function Body
    auto filter = [N](const auto value) { return (value % N) == 0; };

    for (const auto val : my_vector)
    {
        std::cout << std::boolalpha << filter(val) << '\n';
    }
    std::cout << '\n';

    return 0;
}
