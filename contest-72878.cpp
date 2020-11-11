#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t, a, b;
    cin >> t >> a >> b;
    int x = 0, y = 0;
    int i = 0;
    bool ar = true;
    while (i < t)
    {
        if (ar)
        {
            ++x;
            i += 1 + a;
            ar = false;
        }
        else
        {
            ++y;
            i += 1 + b;
            ar = true;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}
