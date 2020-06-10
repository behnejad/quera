#include <iostream>
#include <set>
#include <map>

using namespace std;

#define N 4

int main()
{
    int t, n, q;
    cin >> n >> q;
    t = n;

    long b[N], temp;
    map<long, set<int>> index[N];
    map<long, set<int>> * array[N];

    while (n--)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> b[i];
            if (index[i].count(b[i]) == 0)
            {
                index[i][b[i]] = set<int>();
            }
            index[i][b[i]].insert(n);
        }
    }

    while (q--)
    {
        int c = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> temp;
            if (temp != -1)
            {
                b[c] = temp;
                array[c] = &index[i];
                ++c;
            }
        }

        if (c == 0)
        {
            cout << t << endl;
            continue;
        }
        else
        {
            bool p = false;
            for (int i = 0; i < c; ++i)
            {
                if (array[i]->count(b[i]) == 0)
                {
                    cout << 0 << endl;
                    p = true;
                    break;
                }
            }

            if (p)
                continue;

            if (c == 1)
            {
                cout << array[0]->at(b[0]).size() << endl;
                continue;
            }

            int count = 0, t = 0;
            for (int x : array[0]->at(b[0]))
            {
                t = 0;
                for (int i = 1; i < c; ++i)
                {
                    if (array[i]->count(b[i]) == 0)
                        break;
                    else if (array[i]->at(b[i]).count(x))
                        ++t;
                }

                if (t == c - 1)
                    ++count;
            }

            cout << count << endl;
        }
    }

    return 0;
}
