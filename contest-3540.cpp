#include <iostream>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    int xx = 0, yy = 0;

    if (n % x == 0)
    {
        cout << n / x << " " << 0 << endl;
    }
    else if (n % y == 0)
    {
        cout << 0 << " " << n / y << endl;
    }
    else
    {
        while (n >= x || n >= y)
        {
            if (n % x == 0)
            {
                xx += n / x;
                n = 0;
                break;
            }
            else if (n % y == 0)
            {
                yy += n / y;
                n = 0;
                break;
            }
            else if (x > y)
            {
                if (n >= x)
                {
                    n -= x;
                    ++xx;
                }
                else if (n >= y)
                {
                    n -= y;
                    ++yy;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (n >= y)
                {
                    n -= y;
                    ++yy;
                }
                else if (n >= x)
                {
                    n -= x;
                    ++xx;
                }
                else
                {
                    break;
                }
            }
        }

        if (n > 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << xx << " " << yy << endl;
        }
    }

    return 0;
}
