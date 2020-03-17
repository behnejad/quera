#include <iostream>

using namespace std;

int ** array;
long long ** scores;
int m;

void start_game(int i, int j, int asb)
{
    long long t = 0;
    long long local = 0;

    if (i == 0)
    {
        if (j == 0)
        {
            scores[i][j] = array[i][j];
        }
        else if (scores[i][j - 1] == 0)
        {
            scores[i][j] = array[i][j];
        }
        else if (scores[i][j - 1] == -1)
        {
            start_game(i, j - 1, asb);
        }
        scores[i][j] = array[i][j] + scores[i][j - 1];
    }
    else
    {
        if (j != 0)
        {
            if (scores[i][j - 1] != 0)
            {
                if (scores[i][j] == -1)
                {
                    start_game(i, j - 1, asb);
                }

                if (scores[i][j - 1] != 0)
                {
                    t = array[i][j] + scores[i][j - 1];

                    if (t > local)
                    {
                        local = t;
                    }
                }
            }
        }

        if (i >= 2)
        {
            if (asb & 1)
            {
                if (j < (m - 1))
                {
                    if (scores[i - 2][j + 1] != 0)
                    {
                        if (scores[i - 2][j + 1] == -1)
                        {
                            start_game(i - 2, j + 1, asb + 1);
                        }

                        if (scores[i - 2][j + 1] != 0)
                        {
                            t = array[i][j] + scores[i - 2][j + 1];

                            if (t > local)
                            {
                                local = t;
                            }
                        }
                    }
                }
            }
            else
            {
                if (j > 0)
                {
                    if (scores[i - 2][j - 1] != 0)
                    {
                        if (scores[i - 2][j - 1] == -1)
                        {
                             start_game(i - 2, j - 1, asb + 1);
                        }

                         if (scores[i - 2][j - 1] != 0)
                         {
                             t = array[i][j] + scores[i - 2][j - 1];

                             if (t > local)
                             {
                                 local = t;
                             }
                         }
                    }
                }
            }
        }

        scores[i][j] = local;
    }
}

int main()
{
    int n;
    cin >> n >> m;

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

    long long maxi = 0;
    for (int j = 0; j < m; ++j)
    {
        if (scores[n-1][j] == -1)
        {
            start_game(n-1, j, 0);
        }

        if (maxi < scores[n-1][j])
        {
            maxi = scores[n-1][j];
        }
    }

    cout << maxi << endl;
    return 0;
}
