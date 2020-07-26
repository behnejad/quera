#include <iostream>
#include <map>

using namespace std;

typedef long ull;

int main()
{
    int n, t;
    ull res = 0;

    cin >> n;
    map<int, int> items;

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        if (items.count(t))
        {
            items[t] += 1;
        }
        else
        {
            items[t] = 1;
        }
    }

    for (pair<int, int> x : items)
    {
        for (pair<int, int> y : items)
        {
            if (x.first >= y.first)
            {
                res += ((ull) x.second) * ((ull) y.second) * ((ull) (x.first / y.first));
            }
        }
    }

    cout << res << endl;
    return 0;
}
