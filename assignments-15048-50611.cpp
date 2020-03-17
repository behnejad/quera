#include <iostream>

using namespace std;

int ** array;
long long ** scores;
int m;

int main()
{
    int n, m;
    cin >> n >> m;

    if (n % 2 == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    array = new int *[n];
    scores = new long long *[n];
    int asb = 0;

    for (int i = 0; i < n; ++i)
    {
        array[i] = new int[m];
        scores[i] = new long long[m];
        for (int j = 0; j < m; ++j)
        {
            cin >> asb;
            array[i][j] = asb;
            scores[i][j] = (asb == 0) ? 0 : -1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (array[i][j] != 0)
            {
                if (i & 1)
                {
                    scores[i][j] = 0;
                }
                else if (i == 0)
                {
                    if (j > 0)
                    {
                        if (array[i][j] != 0)
                        {
                            scores[i][j] = array[i][j] + scores[i][j - 1];
                        }
                    }
                    else
                    {
                        if (array[i][j] != 0)
                        {
                            scores[i][j] = array[i][j];
                        }
                    }
                }
                else
                {
                    bool zoj = ((i >> 1) - 1) % 2 == 0;

                    if (j == 0)
                    {
                        if (j < (m - 1) && !zoj && scores[i - 2][j + 1] != 0)
                        {
                            scores[i][j] = array[i][j] + scores[i - 2][j + 1];
                        }
                        else
                        {
                            scores[i][j] = 0;
                        }
                    }
                    else if (j == m - 1)
                    {
                        long long a1 = 0, a2 = 0;

                        if (m > 1 && zoj && scores[i - 2][j - 1] != 0)
                        {
                            a1 = array[i][j] + scores[i - 2][j - 1];
                        }

                        if (scores[i][j - 1] != 0)
                        {
                            a2 = array[i][j] + scores[i][j - 1];
                        }

                        scores[i][j] = max(a1, a2);
                    }
                    else
                    {
                        long long a1 = 0, a2 = 0, a3 = 0;

                        if (j > 0 && scores[i][j - 1] != 0)
                        {
                            a1 = array[i][j] + scores[i][j - 1];
                        }

                        if (j > 0 && zoj && scores[i - 2][j - 1] != 0)
                        {
                            a2 = array[i][j] + scores[i - 2][j - 1];
                        }

                        if (j < (m - 1) && !zoj && scores[i - 2][j + 1] != 0)
                        {
                            a3 = array[i][j] + scores[i - 2][j + 1];
                        }

                        scores[i][j] = max(a1, max(a2, a3));
                    }
                }
            }
        }
    }

    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << scores[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    long long maxi = 0;
    for (int j = 0; j < m; ++j)
    {
        if (maxi < scores[n-1][j])
        {
            maxi = scores[n-1][j];
        }
    }

    cout << maxi << endl;
    return 0;
}
