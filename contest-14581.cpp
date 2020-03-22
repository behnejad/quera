#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n <= 1)
    {
        cout << 0 << endl;
    }
    else
    {
        if (n & 1)
        {
            long long half = n >> 1;
            long double res = half * (half + 1);
            res /= (n + 1);
            cout << res << endl;
        }
        else
        {
            long long half = n >> 1;
            long double res = half * (half - 1);
            res += half;
            res /= (n + 1);
            cout << res << endl;
        }
    }

    return 0;
}
