#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, pair<int, int>> id_col_h;
    map<int, vector<int>> col_ids;

    for (int i = 1; i <= 30000; ++i)
    {
        id_col_h[i] = make_pair(i, 1);
        col_ids[i] = vector<int>(1, i);
    }

    string t;
    int m, a, b,cola, colb, hb;
    cin >> m;

    while (m--)
    {
        cin >> t >> a;
        if (t == "Height")
        {
            cout << id_col_h[a].second << endl;
        }
        else
        {
            cin >> b;
            cola = id_col_h[a].first;
            colb = id_col_h[b].first;
            hb = col_ids[colb].size();

            vector<int> & q = col_ids[colb];
            for (int x : col_ids[cola])
            {
                q.push_back(x);
                pair<int, int> & u = id_col_h[x];
                u.first = colb;
                u.second = ++hb;
            }

            col_ids[cola].clear();
        }
    }

    return 0;
}
