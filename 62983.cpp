#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool a = false, b = false, c = false;

    if (n >= 5)
    {
        c = true;
        n -= 5;
    }

    if (n >= 3)
    {
        b = true;
        n -= 3;
    }

    if (n >= 1)
    {
        a = true;
    }

    cout << (a ? "Yes" : "No") << endl << (b ? "Yes" : "No") << endl << (c ? "Yes" : "No") << endl;

    return 0;
}
