#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;

    long double res = 0;
    for (int i = -10; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            res += pow(i + j, 3) / pow(j, 2);
        }
    }

    cout << res << endl;
    return 0;
}
