#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n <= 2 || m <= 2)
    {
        cout << 0 << endl;
    }
    else
    {
        int count = 0;
        vector<vector<int>> mt;
        vector<int> row;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int t;
                cin >> t;
                row.push_back(t);
            }

            mt.push_back(move(row));
        }

        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 1; j < m - 1; ++j)
            {
                if (mt[i][j] < mt[i - 1][j] && mt[i][j] < mt[i + 1][j] &&
                        mt[i][j] > mt[i][j - 1] && mt[i][j] > mt[i][j + 1])
                {
                    ++count;
                }
                else if (mt[i][j] > mt[i - 1][j] && mt[i][j] > mt[i + 1][j] &&
                        mt[i][j] < mt[i][j - 1] && mt[i][j] < mt[i][j + 1])
                {
                    ++count;
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}
