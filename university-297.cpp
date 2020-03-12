#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long double x, n;
    cin >> x >> n;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        long double res = 1;

        long double sorat = x;
        long i = 1;
        long double makhraj = 1;

        while (n > 0)
        {
            res += sorat / makhraj;

            sorat *= x;
            makhraj *= (++i);

            --n;
        }

        cout << fixed << setprecision(3) << res << endl;
    }
    return 0;
}
