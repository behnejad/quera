#include <iostream>
#include <string>
#include <stack>

using namespace std;

int count = 0;
int visit[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
stack<pair<int, int>> path;

void print_path()
{
    stack<pair<int, int>> local;
    while (path.size())
    {
        local.push(path.top());
        path.pop();
    }

    while (local.size())
    {
        pair<int, int> & point = local.top();
        cout << "(" << point.first << ", " << point.second << ") ";
        path.push(point);
        local.pop();
    }

    cout << endl;
}

void dfs(char * ptr, int i, int j)
{
    path.push(make_pair(i, j));

    if (*ptr == 0)
    {
//        print_path();
        ++count;
    }
    else if (*ptr == 'R')
    {
        if (i == 0 && visit[1][j] == 0)
        {
            visit[1][j] = 1;
            dfs(ptr + 1, 1, j);
            visit[1][j] = 0;

            if (visit[2][j] == 0)
            {
                visit[1][j] = 1;
                visit[2][j] = 1;
                dfs(ptr + 1, 2, j);
                visit[1][j] = 0;
                visit[2][j] = 0;
            }
        }
        else if (i == 1 && visit[2][j] == 0)
        {
            visit[2][j] = 1;
            dfs(ptr + 1, 2, j);
            visit[2][j] = 0;
        }
    }
    else if (*ptr == 'L')
    {
        if (i == 1 && visit[0][j] == 0)
        {
            visit[0][j] = 1;
            dfs(ptr + 1, 0, j);
            visit[0][j] = 0;
        }
        else if (i == 2 && visit[1][j] == 0)
        {
            visit[1][j] = 1;
            dfs(ptr + 1, 1, j);
            visit[1][j] = 0;

            if (visit[0][j] == 0)
            {
                visit[1][j] = 1;
                visit[0][j] = 1;
                dfs(ptr + 1, 0, j);
                visit[1][j] = 0;
                visit[0][j] = 0;
            }
        }
    }
    else if (*ptr == 'D')
    {
        if (j == 1 && visit[i][2] == 0)
        {
            visit[i][2] = 1;
            dfs(ptr + 1, i, 2);
            visit[i][2] = 0;
        }
        else if (j == 0 && visit[i][1] == 0)
        {
            visit[i][1] = 1;
            dfs(ptr + 1, i, 1);
            visit[i][1] = 0;

            if (visit[i][2] == 0)
            {
                visit[i][1] = 1;
                visit[i][2] = 1;
                dfs(ptr + 1, i, 2);
                visit[i][2] = 0;
                visit[i][1] = 0;
            }
        }
    }
    else // *ptr == 'U'
    {
        if (j == 1 && visit[i][0] == 0)
        {
            visit[i][0] = 1;
            dfs(ptr + 1, i, 0);
            visit[i][0] = 0;
        }
        else if (j == 2 && visit[i][1] == 0)
        {
            visit[i][1] = 1;
            dfs(ptr + 1, i, 1);
            visit[i][1] = 0;

            if (visit[i][0] == 0)
            {
                visit[i][0] = 1;
                visit[i][1] = 1;
                dfs(ptr + 1, i, 0);
                visit[i][1] = 0;
                visit[i][0] = 0;
            }
        }
    }
    path.pop();
}

int main()
{
    string dir;
    cin >> dir;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            visit[i][j] = 1;
            dfs(const_cast<char *>(dir.c_str()), i, j);
            visit[i][j] = 0;
        }
    }

    cout << count << endl;
    return 0;
}
