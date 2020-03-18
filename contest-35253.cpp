#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        vector<pair<int, int>> m;
        for (int i = 0; i < n; ++i)
        {
            int t;
            cin >> t;
            m.emplace_back(i + 1, t);
        }

        while (m.size() != 1)
        {
            if (m[0].second < m[1].second)
            {
                m.erase(m.begin());
            }
            else
            {
                m.erase(m.begin() + 1);
            }
        }

        cout << m[0].first << endl;
    }

    return 0;
}
