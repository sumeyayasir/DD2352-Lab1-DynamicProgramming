#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

const int infinity = 1e8;

int coins(int n, int a, int b, int c)
{
    if (n < 0)
        return infinity;

    if (n == 0)
        return 0;

    int result = n;

    // silver
    int a_result = coins(n - a, a, b, c);
    if (a_result != infinity)
        result = min(result, 1 + a_result);

    // guld
    int b_result = coins(n - b, a, b, c);
    if (b_result != infinity)
        result = min(result, 1 + b_result);

    // platina
    int c_result = coins(n - c, a, b, c);
    if (c_result != infinity)
        result = min(result, 1 + c_result);

    return result;
}

int main()
{
    int n, a, b, c;

    if (cin >> n >> a >> b >> c)
    {
        cout << coins(n, a, b, c) << endl;
    }

    return 0;
}