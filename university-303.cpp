#include <iostream>

using namespace std;

int main()
{
    long i, j;
    cin >> i >> j;

    if (i == 1 && j == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << i << endl;
        while (j != 1)
        {
            int c = j - i;
            cout << c << endl;
            j = i;
            i = c;
        }
    }

    return 0;
}
