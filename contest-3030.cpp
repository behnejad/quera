#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (x != y)
    {
        cout << 1 << endl << 7 << " " << 7 << endl;
    }
    else
    {
        for (int i = 2; i < 8; ++i)
        {
            if (i != x)
            {
                cout << 1 << endl << i << " " << i << endl;
                break;
            }
        }
    }
    return 0;
}
