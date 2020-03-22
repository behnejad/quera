#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 3)
    {
        cout << n - 1 << endl;
    }
    else
    {
        vector<vector<int>> nodes(n);
        while(--n)
        {
            int i, j;
            cin >> i >> j;
            nodes[i - 1].push_back(j - 1);
            nodes[j - 1].push_back(i - 1);
        }

        cout << accumulate(nodes.begin(), nodes.end(), 0, [](int res, vector<int> & i) {
            return max(res, (int) i.size());
        }) << endl;
    }
    return 0;
}
