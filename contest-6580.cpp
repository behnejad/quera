#include <iostream>

using namespace std;

int main()
{
    int x, y, r, dx, dy;
    cin >> x >> y >> r >> dx >> dy;
    if (dx >= x && dx <= (x + r) && dy <= y && dy >= (y - r))
    {
        cout << "Mahdi" << endl;
    }
    else
    {
        cout << "Parsa" << endl;
    }
    return 0;
}
