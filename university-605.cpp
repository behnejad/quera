#include <iostream>

using namespace std;

long jaygasht(int i, int j)
{
    if (i < j)
    {
        swap(i, j);
    }

    long long res = 1;
    long long j2 = j;
    while (j2 > 0)
    {
        res *= (i + j2);
        --j2;
    }

    while (j > 1)
    {
        res /= j;
        --j;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << n << endl;
    }
    else
    {
        int count = 0;

        for (int i = 0; i <= n; i += 2)
        {
            int k = jaygasht(n - i, (i >> 1));
//            cout << "i: " << n - i << "\tj: " << (i >> 1) << "\tk: " << k << endl;
            count += k;
        }

        cout << count << endl;
    }
    return 0;
}
