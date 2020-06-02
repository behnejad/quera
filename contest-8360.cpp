#include <iostream>
#include <vector>

using namespace std;

long long map[1000][1000];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> map[i][j];
        }
    }

    int q;
    cin >> q;

    char t;
    int r, l;
    long long k;

    while (q--)
    {
        cin >> t >> l >> r >> k;

        if (t == 'R')
        {
            for (int i = l - 1; i < r; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    map[i][j] /= k;
                }
            }
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = l - 1; j < r; ++j)
                {
                    map[i][j] /= k;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << map[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
