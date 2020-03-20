#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> map(n);
    for (int i = 0; i < n; ++i)
    {
        map[i].resize(m, 0);
    }

    while (c--)
    {
        int i, j;
        cin >> i >> j;
        map[i - 1][j - 1] = -1;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (map[i][j] == 0)
            {
                if (i > 0)
                {
                    // <-
                    if (map[i - 1][j] == -1)
                    {
                        ++map[i][j];
                    }
                }

                if (j > 0)
                {
                    // ^
                    if (map[i][j - 1] == -1)
                    {
                        ++map[i][j];
                    }
                }

                if (i > 0 && j > 0)
                {
                    // <-^
                    if (map[i - 1][j - 1] == -1)
                    {
                        ++map[i][j];
                    }
                }

                if (i < n - 1)
                {
                    // !^
                    if (map[i + 1][j] == -1)
                    {
                        ++map[i][j];
                    }
                }

                if (j < m - 1)
                {
                    // ->
                    if (map[i][j + 1] == -1)
                    {
                        ++map[i][j];
                    }
                }

                if (j < m - 1 && i < n - 1)
                {
                    // !^->
                    if (map[i + 1][j + 1] == -1)
                    {
                        ++map[i][j];
                    }
                }

                if (i > 0 && j < m - 1)
                {
                    // <-!^
                    if (map[i - 1][j + 1] == -1)
                    {
                        ++map[i][j];
                    }
                }

                if (i < n - 1 && j > 0)
                {
                    // ^->
                    if (map[i + 1][j - 1] == -1)
                    {
                        ++map[i][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (map[i][j] == -1)
            {
                cout << "* ";
            }
            else
            {
                cout << map[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
