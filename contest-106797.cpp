#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int a)
{
    if (a <= 1)
    {
        return false;
    }
    else if (a == 2)
    {
        return true;
    }

    int to = (int) sqrt(a);

    for (auto i = 2; i <= to; ++i)
    {
        if ((a % i) == 0)
        {
            return false;
        }
    }

    return true;
}


int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> map(n, vector<int>(m, 0));

    for (auto i = 0; i < n; ++i)
    {
        for (auto j = 0; j < m; ++j)
        {
            cin >> map[i][j];
        }
    }

    int i = 0, j = 0;

    while (k--)
    {
        auto c = map[i][j];
        if (is_prime(c))
        {
            i = n - i - 1;
            j = m - j - 1;
        }
        else
        {
            switch (c % 4)
            {
                case 0:
                    if (j == m - 1)
                    {
                        j = 0;
                    }
                    else
                    {
                        ++j;
                    }
                    break;
                case 1:
                    if (i == n - 1)
                    {
                        i = 0;
                    }
                    else
                    {
                        ++i;
                    }
                    break;
                case 2:
                    if (j == 0)
                    {
                        j = m - 1;
                    }
                    else
                    {
                        --j;
                    }
                    break;
                case 3:
                    if (i == 0)
                    {
                        i = n - 1;
                    }
                    else
                    {
                        --i;
                    }
                    break;
            }
        }
    }

    cout << i + 1 << " " << j + 1 << endl;

    return 0;
}
