#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    long sum = 0;
    vector<vector<int>> matris;
    vector<int> row;

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int t;
            cin >> t;
            row.push_back(t);
        }
        matris.push_back(move(row));
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        sum += matris[x - 1][y - 1];
    }

    cout << sum << endl;

    return 0;
}
