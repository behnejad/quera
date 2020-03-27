#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, m, lm = 2, count = 0;
    cin >> n >> m;
    if (m < 2 || n < 4)
    {
        cout << count << endl;
    }
    else
    {
        vector<string> rows;
        string row;
        for (int i = 0; i < n; ++i)
        {
            cin >> row;
            rows.push_back(move(row));
        }

        while (true)
        {
            if ((lm + 1) <= m && ((lm + 1) << 1) <= n)
            {
                ++lm;
            }
            else
            {
                break;
            }
        }

        for (int i = 2; i <= lm; ++i)
        {
            int nn = i << 1;
            for (int j = 0; j <= n - nn; ++j)
            {
                for (int k = 0; k <= m - i; ++k)
                {
                    bool has_l = true;
                    for (int q = 0; q < nn && has_l; ++q)
                    {
                        if (rows[j + q][k] != '*')
                        {
                            has_l = false;
                        }
                    }

                    if (has_l)
                    {
                        for (int q = 0; q < i && has_l; ++q)
                        {
                            if (rows[j + nn - 1][k + q] != '*')
                            {
                                has_l = false;
                            }
                        }

                        if (has_l)
                        {
                            ++count;
                        }
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
