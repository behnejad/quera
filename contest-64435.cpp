#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int t;
    int n, m;
    float aria = 0;

    cin >> t;

    vector<string> map;

    while (t--)
    {
        cin >> n >> m;
        map.resize(n);
        aria = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> map[i];
        }

        for (int i = 0; i < m; ++i)
        {
            int row = 0;
            char r;
            while ((r = map[row][i]) == '.') ++row;
            if (r == '_')
            {
                aria += (n - row - 1);
            }
            else if (r == '/' || r == '\\')
            {
                aria += (n - row - 1) + 0.5;
            }
        }

        cout << fixed << setprecision(3) << aria << endl;
    }

    return 0;
}
