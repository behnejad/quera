#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_paladium(string & a)
{
    int i = 0;
    int j = a.size() - 1;
    while (i <= j)
    {
        if (a.at(i) != a.at(j))
        {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}

int main()
{
    long b, c, x = 0, t10 = 0;
    string xx, a;
    cin >> a >> b >> c;

    if (b == 10)
    {
        t10 = stol(a);
    }
    else
    {
        long base = 1;
        for_each(a.rbegin(), a.rend(), [&](char & i) {
            t10 += (base * (i - '0'));
            base *= b;
        });
    }

    while (t10 > c)
    {
        x *= 10;
        x += t10 % c;
        t10 /= c;
    }

    x *= 10;
    x += t10;

    xx = to_string(x);

    cout << (is_paladium(xx) ? "YES" : "NO") << endl;

    return 0;
}
