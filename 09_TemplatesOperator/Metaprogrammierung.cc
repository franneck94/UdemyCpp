#include <iostream>

// FACULTY

// 5!
// faculty<5>: val = fac<4> * 5 => 24 * 5 = 120
// faculty<4> : val = fac<3> * 4 => 6 * 4 = 24
// faculty<3> : val = fac<2> * 3 => 2 * 3 = 6
// faculty<2> : val = fac<1> * 2 => 1 * 2 = 2
// faculty<2>: val = 1

template <const int n>
class faculty
{
public:
    static const int val = faculty<n - 1>::val * n;
};

template <>
class faculty<1>
{
public:
    static const int val = 1;
};

///////////////////

// sum from 1 to n
template <const int n>
class sum
{
public:
    static const int val = sum<n - 1>::val + n;
};

template <>
class sum<1>
{
public:
    static const int val = 1;
};

int main()
{
    // 5! = 5 * 4 * 3 * 2 * 1
    // n! = n * (n-1) * ... * 1
    std::cout << "5! = " << faculty<5>::val << std::endl;

    // 5 + 4 + 3 + 2 + 1 = 15
    std::cout << "Sum from 1 to n=5: " << sum<5>::val << std::endl;

    return 0;
}
