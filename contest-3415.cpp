#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n, p = 0;
    cin >> n;
    vector<pair<int, int>> cells;
    vector<bool> bad(n, false);

    while (n--)
    {
        int p, q;
        cin >> p >> q;
        cells.push_back(make_pair(p, q));
    }

    for (int i = 0; i < cells.size(); ++i)
    {
        for (int j = 0; j < cells.size(); ++j)
        {
            if (i != j && cells[i].first >= cells[j].first && cells[i].second <= cells[j].second)
            {
                bad[i] = true;
            }
        }
    }

    for (int i = 0; i < bad.size(); ++i)
    {
        if (bad[i])
        {
            ++p;
        }
    }

    cout << cells.size() - p << endl;

    return 0;
}
