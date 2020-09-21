#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;
    vector<string> row(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> row[i];
    }

    for (int i = 0; i < m; ++i)
    {
        int c = 0;
        for (int j = 0; j < n; ++j)
        {
            if (row[j][i] == 'W')
                ++c;
        }

        cout << (c % 2 ? 'F' : 'B');
    }
    cout << endl;

    return 0;
}
