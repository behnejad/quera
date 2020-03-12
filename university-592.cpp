#include <iostream>

using namespace std;

int main()
{
    long i, j;
    cin >> i >> j;

    if (i > j)
    {
        swap(i, j);
    }

    if (i == 0)
    {
        cout << 0 << " ";
    }

    if (i == 1 && j == 1)
    {
        cout << 1 << " ";
    }

    for (long k = 1; k < j; ++k)
    {
        if ((j % k) == i)
        {
            cout << k << " ";
        }
    }

    cout << endl;
    return 0;
}
