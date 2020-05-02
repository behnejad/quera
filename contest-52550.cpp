#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, bool>> array(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> array[i].first;
        array[i].second = false;
    }

    vector<pair<int, int>> res;

    for (int i = 0; i < n; ++i)
    {
        if (array[i].second == true)
        {
            continue;
        }

        for (int j = i + 1; j < n; ++j)
        {
            if (array[j].second == true)
            {
                continue;
            }

            if (array[j].first == array[i].first)
            {
                array[j].second = true;
                res.emplace_back(i + 1, j + 1);
                break;
            }
        }
    }

    cout << res.size() << endl;
    for (pair<int, int> & x : res)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
