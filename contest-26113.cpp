#include <iostream>
#include <vector>
#include <limits>
#include <cstring>

using namespace std;
typedef unsigned long long myl;
myl ma = numeric_limits<myl>::max();

int main()
{
    int n;
    myl res = 0;
    cin >> n;
    myl a[n];
    char b[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i)
    {
        int l = (i == 0 ? 0 : i - 1), r = (i == n - 1 ? n - 1 : i + 1), index = i, step = 1;
        myl dis_r, dis_l;
        memset(b, 0, n);
        b[i] = 1;

        while (step < n)
        {
            dis_r = a[r] - a[index];
            if (b[r] == 1 || dis_r == 0)
            {
                dis_r = ma;
            }

            dis_l = a[index] - a[l];
            if (b[l] == 1 || dis_r == 0)
            {
                dis_l = ma;
            }

            b[index] = 1;

            if (dis_l < dis_r)
            {
                res += dis_l;
                index = l;
                l = (l == 0 ? 0 : index - 1);
            }
            else
            {
                res += dis_r;
                index = r;
                r = (r == n - 1 ? n - 1 : r + 1);
            }

            ++step;
        }
    }

    cout << res << endl;
    return 0;
}
