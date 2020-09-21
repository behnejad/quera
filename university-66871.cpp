#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

using namespace std;

enum jahat {
    OTHER,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

bool is_prime(int n)
{
    int m = sqrt(n);
    if ((m * m) == n)
        return false;
    else
        ++m;

    for (int i = 2; i < m; ++i)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

vector<vector<pair<int, bool>>> map;
deque<char> road;
int n;
int sx, sy, ex, ey;

bool find(int x, int y)
{
    if (x == ex && y == ey)
        return true;

    map[x][y].second = true;

    if (x > 0 && !map[x - 1][y].second && is_prime(map[x - 1][y].first))
    {
        road.push_back('U');
        if (find(x - 1, y))
            return true;
        road.pop_back();
    }

    if (x < (n - 1) && !map[x + 1][y].second && is_prime(map[x + 1][y].first))
    {
        road.push_back('D');
        if (find(x + 1, y))
            return true;
        road.pop_back();
    }

    if (y > 0 && !map[x][y - 1].second && is_prime(map[x][y - 1].first))
    {
        road.push_back('L');
        if (find(x, y - 1))
            return true;
        road.pop_back();
    }

    if (y < (n - 1) && !map[x][y + 1].second && is_prime(map[x][y + 1].first))
    {
        road.push_back('R');
        if (find(x, y + 1))
            return true;
        road.pop_back();
    }

    map[x][y].second = false;
    return false;
}

void job()
{
    cin >> n;
    map.resize(n);
    road.clear();

    for (int i = 0; i < n; ++i)
    {
        map[i].resize(n);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> map[i][j].first;
            map[i][j].second = false;
        }
    }

    cin >> sx >> sy >> ex >> ey;
    map[sx][sy].second = true;

    if (find(sx, sy))
    {
        while (road.size())
        {
            cout << road.front();
            road.pop_front();
        }
    }
    else
    {
        cout << "No Monaseb Masir!";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        job();

    return 0;
}
