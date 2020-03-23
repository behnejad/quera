#include <iostream>

using namespace std;

int main()
{
    long long f = 0, t = 0, n, o = 0;
    cin >> n;
    while (n--)
    {
        int q;
        cin >> q;
        if (q == 5)
        {
           ++f;
        }
        else
        {
            ++t;
        }
    }

    o = t;
    f += t;
    cout << 5 << " " << f << " " << -o << endl;

    return 0;
}
