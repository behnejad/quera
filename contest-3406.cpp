#include <iostream>

using namespace std;

int main()
{
    int x, y, xxx, yyy;
    cin >> x >> y;

    if (x == y)
    {
        cout << x << " = " << x << endl;
    }
    else
    {
        xxx = x;
        yyy = y;

        int xx = 0, yy = 0;

        do
        {
            xx *= 10;
            xx += x % 10;
            x /= 10;
        } while(x != 0);

        do
        {
            yy *= 10;
            yy += y % 10;
            y /= 10;
        } while(y != 0);

        if (xx < yy)
        {
            cout << xxx << " < " << yyy << endl;
        }
        else
        {
             cout << yyy << " < " << xxx << endl;
        }
    }

    return 0;
}
