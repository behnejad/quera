#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    vector<ull> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    ull gcd = __gcd(a[0], a[1]);

    for (int i = 2; i < n; ++i)
    {
        if (gcd == 1)
        {
            break;
        }
        else
        {
            gcd = __gcd(gcd, a[i]);
        }
    }


    ull sum = 0;
    if (gcd != 1)
    {
        for (ull & x : a)
        {
            x /= gcd;
        }
    }

    for (ull x : a)
    {
        sum += x;
    }

    cout << sum << endl;
    return 0;
}
