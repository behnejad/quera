#include <iostream>

using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    if (n == 0)
    {
        cout << 20 << endl;
    }
    else if (n == 7)
    {
        cout << x << endl;
    }
    else
    {
        if (x < n)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << x - n << endl;
        }
    }
    return 0;
}
