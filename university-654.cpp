#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool check(int a, int b, int c)
{
    if (a == 0 || b == 0 || c == 0)
    {
        return false;
    }

    if ((a + b + c) != n)
    {
        return false;
    }

    if (((a * a) + (b * b)) == (c * c))
    {
        return true;
    }

    return false;
}

bool new_algorithm(int & r1, int & r2, int & r3)
{
    int max_a = n >> 1;
    vector<long long> ar(3);
    for (int a = 1; a <= max_a; ++a)
    {
        long long a2 = a * a;
        long long k = n - a;
        long long k2 = k * k;
        long long c = (k2 + a2) / (2 * k);
        long long b = n - a - c;

        ar[0] = a;
        ar[1] = b;
        ar[2] = c;
        sort(ar.begin(), ar.end());
        r1 = ar[0];
        r2 = ar[1];
        r3 = ar[2];

        if (check(r1, r2, r3))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    cin >> n;

    if (n < 12)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    else
    {
        int aa = 0, bb = 0, cc = 0;
        if (new_algorithm(aa, bb, cc))
        {
            cout << aa << " " << bb << " " << cc << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
