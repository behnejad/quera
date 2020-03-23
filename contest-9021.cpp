#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<bool, int>> lamps;
    set<int> order;

    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        lamps.emplace_back(true, t);
    }

    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        if (t == 0)
        {
            lamps[i].first = false;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (lamps[i].first)
        {
            order.insert(lamps[i].second);
        }
    }

    for (int x : order)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
