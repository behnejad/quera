#include <iostream>
#include <map>
#include <limits>

using namespace std;

int main()
{
    int n, min = numeric_limits<int>::max(),
            min_id = numeric_limits<int>::max();
    cin >> n;
    map<int, int> set;
    while (n--)
    {
        int t;
        cin >> t;
        if (set.count(t) == 0)
        {
            set[t] = 1;
        }
        else
        {
            set[t] += 1;
        }
    }

    for (const pair<int, int> & x : set)
    {
        if (x.second < min)
        {
            min = x.second;
            min_id = x.first;
        }

        if (x.second == min)
        {
            if (x.first < min_id)
            {
                min_id = x.first;
            }
        }
    }

    cout << min_id << endl;
    return 0;
}
