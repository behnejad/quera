#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, s, a;
    cin >> t;
    while (t--)
    {
        cin >> n >> s >> a;
        s += (n - 1) * a;
        if (s % n)
        {
            cout << -1 << endl;
        }
        else
        {
            s /= n;
            if (s <= a)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << s - a << endl;
            }
        }
    }
    return 0;
}
