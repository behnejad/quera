#include <iostream>
#include <map>
#include <vector>

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
            items.emplace(t, 1);
        }
    }

    vector<pair<int, int>> a(items.size());
    int i = 0;
    for (pair<int, int> x : items)
    {
        a[i] = x;
        ++i;
    }

    for (i = a.size() - 1; i >= 0; --i)
    {
        for(int j = i; j >= 0; --j)
        {
            res += ((ull) a[i].second) * ((ull) a[j].second) * ((ull) (a[i].first / a[j].first));
        }
    }

    cout << res << endl;
    return 0;
}
