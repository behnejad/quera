#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int x, y, s, n, count = 0;
    cin >> x >> y >> s >> n;

    vector<vector<bool>> map(x);
    for (int i = 0; i < x; ++i)
    {
        map[i].resize(y, false);
    }

    while (n--)
    {
        int i, j;
        cin >> i >> j;
        map[i - 1][j - 1] = true;
    }

    set<int> ss;
    for (int i = 1; i <= s; ++i)
    {
        if ((s % i) == 0)
        {
            int j = s / i;
            if (ss.count(j) != 0)
            {
                break;
            }
            else
            {
                ss.insert(j);
                ss.insert(i);
            }
        }
    }

    for (int i : ss)
    {
        int j = s / i;

        if (i <= x && j <= y)
        {
            for (int ii = 0; ii <= (x - i); ++ii)
            {
                for (int jj = 0; jj <= (y - j); ++jj)
                {
                    bool found = true;
                    for (int qq = 0; qq < i && found; ++qq)
                    {
                        for (int ww = 0; ww < j && found; ++ww)
                        {
                            if (map[ii + qq][jj + ww] == true)
                            {
                                found = false;
                                break;
                            }
                        }
                    }

                    if (found)
                    {
                        ++count;
                    }
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
