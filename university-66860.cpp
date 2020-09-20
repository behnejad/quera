#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long  ull;

ull cnt[70];

void calc(ull w, ull h)
{
    if (w > h)
    {
        swap(w, h);
    }

    if (w == 0)
    {
        return;
    }

    int p = log2(w);
    ull x = pow(2, p);

    for (ull i = p, y = h; i >= 0 && y != 0; --i)
    {
        ull a = pow(2, i);
        cnt[i] += (x / a) * (y / a);
        y %= a;
    }

    calc(w - x, h);
}


int main()
{
    ull w, h;
    cin >> w >> h;
    calc(w, h);

    for (int i = 69; i >= 0; --i)
    {
        if (cnt[i] != 0)
        {
            ull a = pow(2, i);
            cout << cnt[i] << " " << a << "*" << a << " tiles" << endl;
        }
    }

    return 0;
}
