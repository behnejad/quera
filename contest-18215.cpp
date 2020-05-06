#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long t;
    int n, count = 0;
    cin >> n;
    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        a[i].first = t % 5;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        a[i].second = t % 5;
    }

    int dif = a[0].first - a[0].second;
    int temp = dif;

    for (int i = 1; i < n; ++i)
    {
        temp = a[i].first - a[i].second;
        if (temp != dif)
        {
            if (dif != 0)
            {
                ++count;
            }

            dif = temp;
        }
    }

    if (temp != 0)
    {
        ++count;
    }

    cout << count << endl;
    return 0;
}
