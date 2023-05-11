#include <algorithm>
#include <iostream>

using namespace std;

int min(int a, int b)
{
    return a > 0 && a < b;
}

int main()
{
    int a = 2;
    int b = 3;

    int res = std::min(a, b);
    cout << res << endl;

    return 0;
}
