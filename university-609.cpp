#include <iostream>
#include <cmath>

using namespace std;

#define N 5

int m[N][N] = {0};
int v[N + 1][N + 1] = {0};

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cin >> n;
        int sq = (int)sqrt(n);
        cout << ((sq * sq == n) ? 1 : 0) << endl;
    }
    else
    {
        int sum = 0;
        int count = 0, state = 0;
        int items = n * n;
        int x = 0, y = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> m[i][j];
                v[i][j] = 1;
            }
        }

        n *= n;
        while (n--)
        {
            sum += m[x][y];
            v[x][y] = 0;

            int sq = (int)sqrt(sum);
            count += (sq * sq == sum) ? 1 : 0;

            if (state == 0)
            {
                if (v[x][y + 1] != 0)
                {
                    y += 1;
                }
                else
                {
                    state = 1;
                    x += 1;
                }
            }
            else if (state == 1)
            {
                if (v[x + 1][y] != 0)
                {
                    x += 1;
                }
                else
                {
                    state = 2;
                    y -= 1;
                }
            }
            else if (state == 2)
            {
                if (x == 0)
                {
                    state = 3;
                    x -= 1;
                }
                else if (v[x][y - 1] != 0)
                {
                    y -= 1;
                }
                else
                {
                    state = 3;
                    x -= 1;
                }
            }
            else
            {
                if (v[x - 1][y] != 0)
                {
                    x -= 1;
                }
                else
                {
                    state = 0;
                    y += 1;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
