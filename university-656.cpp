#include <iostream>
#include <cmath>

using namespace std;

#define N 10

int m1[N][N] = {0};
int m2[N][N] = {0};
int m3[N][N] = {0};

double d = 0;

long long det(int n, int mat[N][N])
{
    long long c, subi, i, j, subj;
    int submat[N][N];
    if (n == 2)
    {
        return( (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    }
    else
    {
        for(c = 0; c < n; c++)
        {
            subi = 0;
            for(i = 1; i < n; i++)
            {
                subj = 0;
                for(j = 0; j < n; j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
        d = d + ((c % 2 == 0 ? 1 : -1) * mat[0][c] * det(n - 1 ,submat));
        }
    }
    return d;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> m1[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> m2[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                m3[i][k] += m1[i][j] * m2[j][k];
            }
        }
    }

    cout << (det(n, m3) % 2 == 1 ? "Danial" : "Farzad") << endl;
    return 0;
}
