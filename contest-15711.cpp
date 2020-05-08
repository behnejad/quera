#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, count;
    map<double, pair<int, int>> a;
    double i, j, k;
    pair<int, int> v(0, 0);

    cin >> n;
    count = n;
    while (n--)
    {
        cin >> i >> j;
        if (i == 0)
        {
            if (j > 0)
            {
                ++v.second;
            }
            else
            {
                ++v.first;
            }
        }
        else
        {
            k = j / i;
            if (a.count(k))
            {
                if (j >= 0)
                {
                    ++a[k].first;
                }
                else
                {
                    ++a[k].second;
                }
            }
            else
            {
                if (j >= 0)
                {
                    a[k] = pair(1, 0);
                }
                else
                {
                    a[k] = pair(0, 1);
                }
            }
        }
    }

    for (decltype(a)::iterator it = a.begin(); it != a.end(); ++it)
    {
        if (it->second.first != 1 || it->second.second != 1)
        {
            if (it->second.first == 0 || it->second.second == 0)
            {
                --count;
            }
            else if (it->second.first == 1 || it->second.second == 1)
            {
                --count;
            }
            else
            {
                count -= 2;
            }
        }
    }

    if ((v.first != 1 || v.second != 1) && (v.first != 0 && v.second != 0))
    {
        if (v.first == 0 || v.second == 0)
        {
            --count;
        }
        else if (v.first == 1 || v.second == 1)
        {
            --count;
        }
        else
        {
            count -= 2;
        }
    }

    cout << count << endl;
    return 0;
}
