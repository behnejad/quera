#include <iostream>
#include <iomanip>

using namespace std;

long double myPow(long double base, unsigned int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    else if (exp % 2 == 0)
    {
        long double m = myPow(base, exp >> 1);
        return m * m;
    }
    else
    {
        return base * myPow(base, exp - 1);;
    }
}

int main()
{
    long double base;
    unsigned int exp;

    cin >> base >> exp;

    cout << fixed << setprecision(3) << myPow(base, exp) << endl;

    return 0;
}
