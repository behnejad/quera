#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    if (k == m * n && (k % 2) == 0)
    {
        cout << -1 << endl;
    }
    else if (k % 2 == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        vector<vector<int>> keys(n);
        for (vector<int> & x : keys)
        {
            x.resize(m, 0);
        }
        while (k--)
        {
            int r, c;
            cin >> r >> c;
            keys[r - 1][c - 1] = 1;
        }
        for (int i = 0; i < keys.size(); ++i)
        {
            for (int j = 0; j < keys[i].size(); ++j)
            {
                if (keys[i][j] == 0)
                {
                    cout << 1 << endl << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
