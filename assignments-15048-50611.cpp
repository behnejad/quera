#include <iostream>
#include <vector>

using namespace std;

int ** array;
long long maxi = 0;
int m;

void start_game(int i, int j, long long sum, int asb)
{
    if (i == 0)
    {
        if (j != 0 && array[i][j - 1] != 0)
        {
            start_game(i, j - 1, sum + array[i][j], asb);
        }
        else
        {
            sum += array[i][j];
            if (maxi < sum)
            {
                maxi = sum;
            }
        }
    }
    else
    {
        if (j != 0 && array[i][j - 1] != 0)
        {
             start_game(i, j - 1, sum + array[i][j], asb);
        }

        if (i >= 2)
        {
            if (asb & 1)
            {
                if (j < (m - 1) && array[i - 2][j + 1] != 0)
                {
                    start_game(i - 2, j + 1, sum + array[i][j], asb + 1);
                }
            }
            else
            {
                if (j > 0 && array[i - 2][j - 1] != 0)
                {
                    start_game(i - 2, j - 1, sum + array[i][j], asb + 1);
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n >> m;

    array = new int *[n];
    int asb = 0;

//    vector<int> row;
    for (int i = 0; i < n; ++i)
    {
        array[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            cin >> asb;
            array[i][j] = asb;
//            row.push_back(asb);
        }
//        array.push_back(move(row));
    }

//    row = array[n - 1];
    for (int j = m - 1; j >= 0; --j)
    {
        if (array[n-1][j] != 0)
        {
            start_game(n-1, j, 0, 0);
        }
    }

    cout << maxi << endl;
    return 0;
}
