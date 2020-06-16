#include <iostream>

using namespace std;

typedef unsigned long long myLong;

myLong nChoosek(myLong n, myLong k)
{
    if (k * 2 > n)
        k = n - k;
    if (k == 0)
        return 1;

    myLong result = n;
    for(myLong i = 2; i <= k; ++i)
    {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    myLong res = 0, t;
    for (int i = 1; i <= n; ++i)
    {
        t = 1;
        for (int j = 1; j <= i; ++j)
        {
            t *= nChoosek(i, j);
        }
        res += t;
    }

    cout << res << endl;

    return 0;
}
