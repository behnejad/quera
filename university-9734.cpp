#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<vector<int>> g;
typedef map<int, int> k;

int getCount(g & a, int index, k & set)
{
    int res = a[index].size();
    if (res == 0)
    {
        set[index] = 0;
        return 0;
    }

    for (int x : a[index])
    {
        if (set.count(x))
        {
            res += set[x];
        }
        else
        {
            res += getCount(a, x, set);
        }
    }

    set[index] = res;
    return res;
}

int main()
{
    int n;
    while (true)
    {
        cin >> n;

        if (n == 0)
            break;

        g array(n);
        k set;
        for (int i = 0; i < n; ++i)
        {
            int c;
            cin >> c;

            while (c--)
            {
                int j;
                cin >> j;

                array[i].push_back(j - 1);
            }
        }

        int index = 0, max = 0;
        for (int i = 0; i < n; ++i)
        {
            int t = getCount(array, i, set);
            if (t > max)
            {
                max = t;
                index = i;
            }
        }

        cout << index + 1 << endl;
    }

    return 0;
}
