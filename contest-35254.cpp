#include <iostream>
#include <string>

using namespace std;

int base2[] = {512, 256, 128, 64, 32, 16, 8, 4, 2, 1};

int main()
{
    int n, s, t, c = 0;
    string a;
    cin >> n >> a >> s >> t;

    if (t < s)
    {
        t = s + t;
        s = t - s;
        t = t - s;
    }

    --t;
    int k = 0;
    for (int i = s; i < t; ++i)
    {
        if (a[i] == 'H')
        {
            ++k;
        }
        else
        {
            for (int x : base2)
            {
                if (k >= x)
                {
                    ++c;
                    k -= x;
                }
                else if (k == 0)
                {
                    break;
                }
            }
        }
    }

    for (int x : base2)
    {
        if (k >= x)
        {
            ++c;
            k -= x;
        }
        else if (k == 0)
        {
            break;
        }
    }


    cout << c << endl;
    return 0;
}
