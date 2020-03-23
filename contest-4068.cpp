#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if (n == 1 && k == 1)
    {
        cout << 1 << endl;
    }
    else if (k == 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else if (k >= n || (n % 2 == 0 && k >= (n / 2)) || (n % 2 == 1 && k >= (n / 2) + 1))
    {
        cout << "Impossible" << endl;
    }
    else
    {
        int last = 1;
        cout << last << " ";
        bool b = true;
        int count;

        if (n & 1)
        {
            k = n / 2 + 1;
            count = n - 1;
        }
        else
        {
            k = n / 2;
            count = n - 2;
        }

        while (count--)
        {
            if (last < k)
            {
                last += k;
            }
            else
            {
                last -= k;
            }

            cout << last << " ";

            if (b)
            {
                --k;
            }
            else
            {
                ++k;
            }

            b = !b;
        }

        if (n % 2 == 0)
        {
            cout << n;
        }

        cout << endl;
    }
    return 0;
}
