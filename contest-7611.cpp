#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int t, j, rem;
    for (int i = 0; i < n; ++i)
    {
        t = 0;
        j = i;

        while (j < n)
        {
            rem = t % k;
            if (rem == a[j])
            {
                ++j;
            }
            else
            {
                if (rem < a[j])
                {
                    t += (a[j] - rem);
                }
                else
                {
                    t += (k - rem + a[j]);
                }
            }
        }

        cout << t << endl;
    }

    return 0;
}
