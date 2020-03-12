#include <iostream>

using namespace std;

int main()
{
    long long a, b, aa, bb, bmm;
    cin >> a >> b;

    if (a == 0)
    {
        cout << (b > 0 ? b : -b) << endl;
    }
    else if (b == 0)
    {
        cout << (a > 0 ? a : -a) << endl;
    }
    else
    {
        aa = a;
        bb = b;

        bmm = b % a;
        while (bmm != 0)
        {
            b = a;
            a = bmm;
            bmm = b % a;
        }

        cout << (a > 0 ? a : -a) << endl;
    }
    return 0;
}
