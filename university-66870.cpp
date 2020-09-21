#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, t;
    cin >> n;

    set<int> des;
    vector<int> arr;
    vector<pair<int, pair<int, int>>> res;

    while(n--)
    {
        cin >> t;
        des.insert(t);
    }

    n = des.size();

    for (int x : des)
    {
        arr.push_back(x);
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            res.push_back(make_pair(abs(arr[i] - arr[j]), make_pair(arr[i], arr[j])));
        }
    }

    sort(res.begin(), res.end(), [](pair<int, pair<int, int>> & a, pair<int, pair<int, int>> & b) {
        if (a.first == b.first)
        {
            if (a.second.first < b.second.first && a.second.first < b.second.second)
            {
                return true;
            }

            if (a.second.second < b.second.first && a.second.second < b.second.second)
            {
                return true;
            }
            return false;
        }
        else
            return a.first < b.first;
    });

    for (pair<int, pair<int, int>> &x : res)
    {
        cout << "[";
        if (x.second.first < x.second.second)
            cout << x.second.first << ", " << x.second.second;
        else
            cout << x.second.second << ", " << x.second.first;
        cout << "]" << endl;
    }

    return 0;
}
