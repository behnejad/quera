#include <iostream>

#define N 30

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
