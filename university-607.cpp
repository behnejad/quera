#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b, c, t;
    cin >> a >> b >> c;

    vector<int> temp;
    vector<vector<int>> m;
    vector<vector<int>> p;

    for (int i = 0; i < a; ++i)
    {
        temp.clear();

        for (int i = 0; i < b; ++i)
        {
            cin >> t;
            temp.push_back(t);
        }

        m.push_back(move(temp));
    }

    for (int i = 0; i < b; ++i)
    {
        temp.clear();

        for (int i = 0; i < c; ++i)
        {
            cin >> t;
            temp.push_back(t);
        }

        p.push_back(move(temp));
    }

    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            int sum = 0;
            for (int k = 0; k < b; ++k)
            {
                sum += m[i][k] * p[k][j];
            }
            cout << sum << " ";
        }
        cout << endl;
    }

    return 0;
}
