#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    k = n;
    vector<string> table(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> table[i];
    }
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "H")
        {
            reverse(table.begin(), table.end());
        }
        else if (s == "V")
        {
            for (int i = 0; i < table.size(); ++i)
            {
                reverse(table[i].begin(), table[i].end());
            }
        }
        else if (s == "90")
        {
            vector<string> temp = table;
            for (int i = 0; i < k; ++i)
            {
                for (int j = 0; j < k; ++j)
                {
                    temp[j][i] = table[k - 1 - i][j];
                }
            }
            table = move(temp);
        }
    }
    for (string & x : table)
    {
        cout << x << endl;
    }
    return 0;
}
