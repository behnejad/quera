#include <iostream>

using namespace std;

int main()
{
    long long p, r, s, p2, r2, s2, res = 0;
    cin >> p >> r >> s >> p2 >> r2 >> s2;

    while (p)
    {
        if (s2)
        {
            if (p <= s2)
            {
                res += p;
                s2 -= p;
                p = 0;
            }
            else
            {
                res += s2;
                p -= s2;
                s2 = 0;
            }
        }
        else if (p2)
        {
            if (p <= p2)
            {
                p2 -= p;
                p = 0;
            }
            else
            {
                p -= p2;
                p2 = 0;
            }
        }
        else if (r2)
        {
            if (p <= r2)
            {
                res -= p;
                r2 -= p;
                p = 0;
            }
            else
            {
                res -= r2;
                p -= r2;
                r2 = 0;
            }
        }
    }

    while (r)
    {
        if (p2)
        {
            if (r <= p2)
            {
                res += r;
                p2 -= r;
                r = 0;
            }
            else
            {
                res += p2;
                r -= p2;
                p2 = 0;
            }
        }
        else if (r2)
        {
            if (r <= r2)
            {
                r2 -= r;
                r = 0;
            }
            else
            {
                r -= r2;
                r2 = 0;
            }
        }
        else if (s2)
        {
            if (r <= s2)
            {
                res -= r;
                s2 -= r;
                r = 0;
            }
            else
            {
                res -= s2;
                r -= s2;
                s2 = 0;
            }
        }
    }

    while (s)
    {
        if (r2)
        {
            if (s <= r2)
            {
                res += s;
                r2 -= s;
                s = 0;
            }
            else
            {
                res += r2;
                s -= r2;
                r2 = 0;
            }
        }
        else if (s2)
        {
            if (s <= s2)
            {
                s2 -= s;
                s = 0;
            }
            else
            {
                s -= s2;
                s2 = 0;
            }
        }
        else if (p2)
        {
            if (s <= p2)
            {
                res -= s;
                p2 -= s;
                s = 0;
            }
            else
            {
                res -= p2;
                s -= p2;
                p2 = 0;
            }
        }
    }

    cout << res << endl;
    return 0;
}
