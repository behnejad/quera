#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n, q;
    cin >> n >> q;

    vector<pair<long, long>> m(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> m[i].first;
        m[i].second = 1;
    }

    char t;
    int x, y;
    while (q--)
    {
        cin >> t >> x >> y;

        if (t == '?')
        {
            int count = 0;

            for (int i = x - 1; i < y; ++i)
            {
                if (m[i].first)
                {
                    ++count;
                }
            }

            cout << count << endl;
        }
        else
        {
            m[x - 1].second += y;
        }

        for (pair<long, long> & q : m)
        {
            if (q.first >= q.second)
            {
                q.first -= q.second;
            }
            else if (q.first > 0)
            {
                q.first = 0;
            }
        }
    }

    return 0;
}
