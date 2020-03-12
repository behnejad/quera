#include <iostream>
#include <vector>

using namespace std;

bool check(vector<pair<int, bool>> & a, int & b)
{
    int c = 0;
    for (pair<int, bool> & i : a)
    {
        if (i.second)
        {
            ++c;
            b = i.first;
        }
    }

    return (c != 1);
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, bool>> a(n);
    for (int i = 0; i < n; ++i)
    {
        a[i].first = i + 1;
        a[i].second = true;
    }

    int b;
    int index = 1;
    int live_count = 1;
    while (check(a, b))
    {
        if (live_count == 1)
        {
            if (a[index].second)
            {
                live_count = 0;
                a[index].second = false;
            }
        }
        else
        {
            if (a[index].second == true)
            {
                ++live_count;
            }
        }

        if (index == a.size() - 1)
        {
            index = 0;
        }
        else
        {
            ++index;
        }
    }

    cout << b << endl;
    return 0;
}
