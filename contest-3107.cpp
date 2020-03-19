#include <iostream>

using namespace std;

int main()
{
    int x, y, i, j;
    cin >> x >> y >> i >> j;

    if (i <= x && j <= y)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}
