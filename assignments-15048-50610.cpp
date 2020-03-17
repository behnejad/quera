#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    int n, k;
    int max = numeric_limits<int>::min();
    int min = numeric_limits<int>::max();
    vector<int> a;

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        a.push_back(t);

        if (max < t)
        {
            max = t;
        }
        if (min > t)
        {
            min = t;
        }
    }

    if (k == 1)
    {
        cout << max << endl;
    }
    else if (k == n || min == a[0] || min == a[n - 1])
    {
        cout << min << endl;
    }
    else
    {

    }

    return 0;
}
