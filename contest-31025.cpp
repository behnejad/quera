#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    cout << (-1) / 2 << endl;
    if (n < 0)
    {
        while (k--)
        {
            if (n == -1)
            {
                break;
            }
            else
            {
                n /= 2;
            }
        }
    }
    else
    {
        while(k--)
        {
            if (n == 0)
            {
                break;
            }
            else
            {
                n /= 2;
            }
        }
    }

    cout << n << endl;

    return 0;
}
