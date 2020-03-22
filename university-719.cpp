#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n, max = 0;
    cin >> n;
    vector<pair<int, int>> array;
    while (n--)
    {
        int i, j;
        cin >> i >> j;
        array.emplace_back(i, j);
    }

    for (int i = 0; i < array.size() - 1; ++i)
    {
        for (int j = i + 1; j < array.size(); ++j)
        {
            int dis = abs(array[i].first - array[j].first) + abs(array[i].second - array[j].second);
            if (max < dis)
            {
                max = dis;
            }
        }
    }

    cout << max << endl;
    return 0;
}
