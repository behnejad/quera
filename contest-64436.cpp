#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    if (n < 3 || m < 3)
    {
        cout << 0;
        return 0;
    }

    vector<string> map(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> map[i];
    }

    int count = 0;

    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = 0; j < m - 2; ++j)
        {
            // ***
            // *.*
            // ..*
            if (map[i][j] == '*' && map[i][j + 1] == '*' && map[i][j + 2] == '*' &&
                    map[i + 1][j] == '*' && map[i + 1][j + 2] == '*' &&
                    map[i + 2][j + 2] == '*')
            {
                ++count;
            }
            // ***
            // *.*
            // *..
            if (map[i][j] == '*' && map[i][j + 1] == '*' && map[i][j + 2] == '*' &&
                    map[i + 1][j] == '*' && map[i + 1][j + 2] == '*' &&
                    map[i + 2][j] == '*')
            {
                ++count;
            }
            // *..
            // *.*
            // ***
            if (map[i][j] == '*' &&
                    map[i + 1][j] == '*' && map[i + 1][j + 2] == '*' &&
                    map[i + 2][j] == '*' && map[i + 2][j + 1] == '*' && map[i + 2][j + 2] == '*')
            {
                ++count;
            }
            // ..*
            // *.*
            // ***
            if (map[i][j + 2] == '*' &&
                    map[i + 1][j] == '*' && map[i + 1][j + 2] == '*' &&
                    map[i + 2][j] == '*' && map[i + 2][j + 1] == '*' && map[i + 2][j + 2] == '*')
            {
                ++count;
            }
            // .**
            // ..*
            // ***
            if (map[i][j + 1] == '*' && map[i][j + 2] == '*' &&
                    map[i + 1][j + 2] == '*' &&
                    map[i + 2][j] == '*' && map[i + 2][j + 1] == '*' && map[i + 2][j + 2] == '*')
            {
                ++count;
            }
            // ***
            // ..*
            // .**
            if (map[i][j] == '*' && map[i][j + 1] == '*' && map[i][j + 2] == '*' &&
                    map[i + 1][j + 2] == '*' &&
                    map[i + 2][j + 1] == '*' && map[i + 2][j + 2] == '*')
            {
                ++count;
            }
            // ***
            // *..
            // **.
            if (map[i][j] == '*' && map[i][j + 1] == '*' && map[i][j + 2] == '*' &&
                    map[i + 1][j] == '*' &&
                    map[i + 2][j] == '*' && map[i + 2][j + 1] == '*')
            {
                ++count;
            }
            // **.
            // *..
            // ***
            if (map[i][j] == '*' && map[i][j + 1] == '*' &&
                    map[i + 1][j] == '*' &&
                    map[i + 2][j] == '*' && map[i + 2][j + 1] == '*' && map[i + 2][j + 2] == '*')
            {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}
