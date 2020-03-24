#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> sq(n);
    for (vector<int> & i : sq)
    {
        i.resize(n, 0);
    }

    int i = 0, j = ((n + 1) / 2) - 1, count = (n * n) - 1, k = m;
    sq[i][j] = k;
    int li = i, lj = j;

    while (count != 0)
    {
        if (i == 0)
        {
            i = n - 1;
        }
        else
        {
            --i;
        }

        if (j == n - 1)
        {
            j = 0;
        }
        else
        {
            ++j;
        }

        if (sq[i][j] != 0)
        {
            i = li;
            j = lj;

            while (sq[i][j] != 0)
            {
                if (i == n - 1)
                {
                    i = 0;
                }
                else
                {
                    ++i;
                }
            }
        }

        ++k;
        sq[i][j] = k;
        li = i;
        lj = j;
        --count;
    }

    for (vector<int> & i : sq)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }



    return 0;
}
