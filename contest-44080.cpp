#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> array(n);

    for (ll i = 0; i < n; ++i)
    {
        cin >> array[i];
    }

    if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        sort(array.begin(), array.end());
        ll count = n;
        for (ll i = n - 1; i > 0; --i)
        {
            if (array[i] + array[i - 1] > x)
            {
                --count;
            }
            else
            {
                break;
            }
        }

        cout << count << endl;
    }
    return 0;
}
