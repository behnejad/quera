#include <iostream>

using namespace std;

int main()
{
    int a , b;
    cin >> a >> b;
    if (a == b)
    {
        cout << "Saal Noo Mobarak!" << endl;
    }
    else if (a > b)
    {
        if (a - b == 1)
        {
            cout << "L" << endl;
        }
        else
        {
            cout << "LL" << endl;
        }
    }
    else
    {
        if (b - a == 1)
        {
            cout << "R" << endl;
        }
        else
        {
            cout << "RR" << endl;
        }
    }
    return 0;
}
