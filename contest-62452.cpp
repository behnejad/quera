#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define is_even(x) ((x % 2) == 0)
#define is_odd(x) ((x % 2) != 0)

int main()
{
    int n, m, s;
    cin >> n >> m >> s;

    if ((is_even(n) && is_even(m) && is_odd(s)) ||
            (m == 1 && is_even(n) && is_odd(s)) ||
            (n == 1 && is_even(m) && is_odd(s)))
    {
        cout << "impossible" << endl;
        return 0;
    }

    cout << "possible" << endl;

    vector<string> map(n);
    for (int i = 0; i < n; ++i)
    {
        map[i].resize(m, 'E');
    }

    if (s == 0)
    {

    }
    else if (m == 1)
    {
        if (is_odd(s))
        {
            map[n >> 1][0] = 'T';
            --s;
        }

        int i = 0;
        while (s)
        {
            map[i][0] = 'T';
            map[n - i - 1][0] = 'T';
            s -= 2;
            ++i;
        }
    }
    else if (n == 1)
    {
        if (is_odd(s))
        {
            map[0][m >> 1] = 'T';
            --s;
        }

        int i = 0;
        while (s)
        {
            map[0][i] = 'T';
            map[0][m - i - 1] = 'T';
            s -= 2;
            ++i;
        }
    }
    if (is_odd(m))
    {
        int middle = (m >> 1);

        int k = 0;
        if (is_odd(s))
        {
            map[k++][middle] = 'T';
            --s;
        }

        for (int j = 0; j < middle && s > 0; ++j)
        {
            for (int i = 0; i < n && s > 0; ++i)
            {
                map[i][j] = 'T';
                map[i][m - j - 1] = 'T';
                s -= 2;
            }
        }

        for (int i = 0; i < n && s; ++i)
        {
            map[k++][middle] = 'T';
            --s;
        }
    }
    else if (is_odd(n))
    {
        int middle = (n >> 1);
        int k = 0;
        if (is_odd(s))
        {
            map[middle][k++] = 'T';
            --s;
        }

        for (int j = 0; j < middle && s > 0; ++j)
        {
            for (int i = 0; i < m && s > 0; ++i)
            {
                map[j][i] = 'T';
                map[n - j - 1][i] = 'T';
                s -= 2;
            }
        }

        for (int i = 0; i < m && s; ++i)
        {
            map[middle][k++] = 'T';
            --s;
        }
    }
    else
    {
        int middle = (n >> 1);
        for (int j = 0; j < middle && s > 0; ++j)
        {
            for (int i = 0; i < m && s > 0; ++i)
            {
                map[j][i] = 'T';
                map[n - j - 1][i] = 'T';
                s -= 2;
            }
        }
    }

    for (string & x : map)
    {
        cout << x << endl;
    }

    return 0;
}
