#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m, l, x, y, count = 0;
    cin >> n >> m >> l >> x >> y;
    string cmd;
    vector<string> map(n);
    cin >> cmd;

    for (int i = 0; i < n; ++i)
    {
        cin >> map[i];
    }

    --x;
    --y;
    --n;
    --m;
    int i = 0;
    while (i < cmd.size())
    {
        if (map[x][y] == '#')
        {
            map[x][y] = ' ';
            ++count;
        }

        if (cmd[i] == 'U')
        {
            if (x == 0 || map[x - 1][y] == 'O')
            {
                ++i;
            }
            else
            {
                --x;
            }
        }
        else if (cmd[i] == 'D')
        {
            if (x == n || map[x + 1][y] == 'O')
            {
                ++i;
            }
            else
            {
                ++x;
            }
        }
        else if (cmd[i] == 'L')
        {
            if (y == 0 || map[x][y - 1] == 'O')
            {
                ++i;
            }
            else
            {
                --y;
            }
        }
        else if (cmd[i] == 'R')
        {
            if (y == m || map[x][y + 1] == 'O')
            {
                ++i;
            }
            else
            {
                ++y;
            }
        }
    }

    cout << count << endl;
    return 0;
}
