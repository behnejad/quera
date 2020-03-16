#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;

#define N 10

int pw[N][N] = { 0 };
int person[N] = { 0 };
int person2[N] = { 0 };
int minx = numeric_limits<int>::max();

bool has_work(int * a, int i)
{
    for (int j = 0; j < N && a[j] != 0; ++j)
    {
        if (a[j] == i)
        {
            return true;
        }
    }

    return false;
}

void find(int p, int sum, int depth)
{
    if (p == depth)
    {
        if (sum < minx)
        {
            minx = sum;
            memcpy(person2, person, sizeof(person));
        }
    }

    for (int i = p; i < depth; ++i)
    {
        for (int j = 1; j <= depth; ++j)
        {
            if (has_work(person, j) == false)
            {
                person[p] = j;
                sum += pw[p][j - 1];
                find(p + 1, sum, depth);
                sum -= pw[p][j - 1];
                person[p] = 0;
            }
        }
    }
}

int main()
{
    int n, t;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
             cin >> pw[i][j];
        }
    }

    find(0, 0, n);

    for (int x : person2)
    {
        if (x != 0)
        {
            cout << x - 1 << endl;
        }
    }

    return 0;
}
