#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> tree;

    while (n--)
    {
        int t;
        cin >> t;
        tree.clear();

        if (t == 1)
        {
            int k;
            cin >> k;
            cout << k << endl;
        }
        else
        {
            vector<int> row;
            for (int i = 0; i < t; ++i)
            {
                for (int j = 0; j < i + 1; ++j)
                {
                    int  k;
                    cin >> k;
                    row.push_back(k);
                }
                tree.push_back(move(row));
            }

            reverse(tree.begin(), tree.end());

            for (int j = 1; j < tree.size(); ++j)
            {
                for (int k = 0; k < tree[j].size(); ++k)
                {
                    tree[j][k] += max(tree[j - 1][k], tree[j-1][k+1]);
                }
            }

            cout << tree[tree.size() - 1][0] << endl;
        }
    }

    return 0;
}
