#include <iostream>

using namespace std;

int main()
{
    long i, j;
    cin >> i >> j;

    for (long k = 1; k < max(i, j); ++k)
    {
        if ((i % k) == j)
        {
            cout << k << " ";
        }
    }

    cout << endl;
    return 0;
}
