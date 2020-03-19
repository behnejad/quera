#include <iostream>

using namespace std;

int main()
{
    long long x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (x1 == x2)
    {
        if (y3 == y2)
        {
            cout << x3 << " " << y1 << endl;
        }
        else
        {
            cout << x3 << " " << y2 << endl;
        }
    }
    else if (x1 == x3)
    {
        if (y3 == y2)
        {
            cout << x2 << " " << y1 << endl;
        }
        else
        {
            cout << x2 << " " << y3 << endl;
        }
    }
    else
    {
        if (y1 == y2)
        {
            cout << x1 << " " << y3 << endl;
        }
        else
        {
            cout << x1 << " " << y2 << endl;
        }
    }
    return 0;
}
