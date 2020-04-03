#include <iostream>

using namespace std;

int main()
{
    int n, x, y;
    long long score = 0, d;
    cin >> n;

    while (n--)
    {
        cin >> x >> y;
        d = (x * x) + (y * y);
        if (d <= 100)
        {
            score += 10;
        }
        else if (d <= 900)
        {
            score += 9;
        }
        else if (d <= 2500)
        {
            score += 8;
        }
        else if (d <= 4900)
        {
            score += 7;
        }
        else if (d <= 8100)
        {
            score += 6;
        }
        else if (d <= 12100)
        {
            score += 5;
        }
        else if (d <= 16900)
        {
            score += 4;
        }
        else if (d <= 22500)
        {
            score += 3;
        }
        else if (d <= 28900)
        {
            score += 2;
        }
        else if (d <= 36100)
        {
            score += 1;
        }
    }

    cout << score << endl;
    return 0;
}
