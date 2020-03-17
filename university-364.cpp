#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<vector<int>> tree;
long maxi;

void find(int r, int index, long sum, int depth)
{
    if (r == depth)
    {
        if (sum > maxi)
        {
            maxi = sum;
        }
    }
    else if (index == 0)
    {
        find(r + 1, 0, sum + tree[r][0], depth);
        find(r + 1, 1, sum + tree[r][1], depth);
    }
    else
    {
        find(r + 1, r, sum + tree[r][r], depth);
        find(r + 1, r + 1, sum + tree[r][r + 1], depth);
    }
}

int main()
{
    int n;
    cin >> n;

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

            maxi = numeric_limits<decltype (maxi)>::min();
            find(1, 0, tree[0][0], t);
            cout << maxi << endl;
        }
    }

    return 0;
}
