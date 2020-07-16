#include <iostream>
#include <set>
#include <queue>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ull k, n, t, tt;
    cin >> k >> n;

    set<ull> k_s;
    queue<ull> k_q;
    for (ull i = 0; i < k; ++i)
    {
        cin >> t;
        k_q.push(t);
        k_s.insert(t);
    }

    n -= k;
    for (ull i = 0; i < n; ++i)
    {
        t = 1;
        for (ull x : k_s)
        {
            if (t < x)
            {
                break;
            }
            else if (t == x)
            {
                ++t;
            }
        }

        tt = k_q.front();
        if (tt != t)
        {
            k_q.pop();
            k_q.push(t);
            k_s.erase(tt);
            k_s.insert(t);
        }
    }

    cout << t << endl;
    return 0;
}
