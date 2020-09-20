#include <iostream>
#include <cmath>

using namespace std;

int count_divisor(int n)
{
    int res = 0;
    int m = sqrt(n);
    if ((m * m) == n)
        ++res;
    else
        ++m;

    for (int i = 1; i < m; ++i)
    {
        if (n % i == 0)
            res += 2;
    }

    return res;
}

int main()
{
    int k;
    cin >> k;
    int khob = 1;
    int counter = 2;

    while (true)
    {
        if (count_divisor(khob) >= k)
        {
            cout << khob << endl;
            break;
        }

        khob += counter;
        ++counter;
    }

    return 0;
}
