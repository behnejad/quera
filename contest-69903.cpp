#include <iostream>

using namespace std;

int change_to_day(int m, int d)
{
    int res = 0;
    if (m <= 6)
    {
        res += 31 * (m - 1);
        res += d;
    }
    else if (m <= 11)
    {
        res += (31 * 6) + ((m - 7) * 30);
        res += d;
    }
    else
    {
        res = 365 - 29 + d;
    }

    return res;
}

int main()
{

    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    int i = change_to_day(m1, d1);
    int j = change_to_day(m2, d2);
    cout << ((i > j) ? (i - j) : (j - i)) << endl;
    return 0;
}
