#include <iostream>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        if (x == y)
        {
            cout << x + x - (x & 1) << endl;
        }
        else if (y == x - 2)
        {
            cout << x + y - (x & 1) << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
