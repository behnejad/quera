#include <iostream>

using namespace std;

int main()
{
    int n, m, nn, mm, k;
    cin >> n >> m;
    nn = 3 * n;
    mm = 3 * m;

    for (int i = 0; i < nn; ++i)
    {
        for (int j = 0; j < mm; ++j)
        {
            k = ((i / n) + 1) * ((j / m) + 1);
            cout << ((k == 1 || k == 3 || k == 4 || k == 9) ? 'X' : '.');
        }

        cout << endl;
    }


    return 0;
}
