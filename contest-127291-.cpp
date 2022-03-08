#include <bits/stdc++.h>
using namespace std;

int distance(int x, int y)
{
    int d = 0;
    while (x != 0 || y != 0)
    {
        if (y == 2 * x)
        {
            d += x;
            break;
        }
        else if (y == 0)
        {
            d += abs(x) / 2;
            break;
        }
        else if (x == 0)
        {
            d += abs(y) / 4;
            break;
        }
        else if ((x == 1 && y == 2) || (x == -1 && y == 2) || (x == 1 && y == -2) || (x == -1 && y == -2))
        {
            d += 1;
            break;
        }
        else
        {
            d += 1;
            if (x > 0)
            {
                if (y > 0)
                {
                    x -= 1;
                    y -= 2;
                }
                else
                {
                    x -= 1;
                    y += 2;
                }
            }
            else
            {
                if (y > 0)
                {
                    x += 1;
                    y -= 2;
                }
                else
                {
                    x = 1;
                    y += 2;
                }
            }
        }
    }

    return d;
}

int main()
{
    int n;
    string s;
    cin >> n;

    while (n--)
    {
        cin >> s;
        int x = 0, y = 0;

        for (auto c : s)
        {
            if (c == 'A')
            {
                x += 2;
            }
            else if (c == 'B')
            {
                x += 1;
                y += 2;
            }
            else if (c == 'C')
            {
                x -= 1;
                y += 2;
            }
            else if (c == 'D')
            {
                x -= 2;
            }
            else if (c == 'E')
            {
                x -= 1;
                y -= 2;
            }
            else if (c == 'F')
            {
                x += 1;
                y -= 2;
            }
        }

        cout << distance(abs(x), abs(y)) << endl;
    }

    return 0;
}
