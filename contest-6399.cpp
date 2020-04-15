#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    long long a[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
    }

    int l, r, k;
    long long res;

    while (m--)
    {
        scanf("%d", &l);
        scanf("%d", &r);
        scanf("%d", &k);

        res = 0;

        for (int i = l - 1; i < r; i += k)
        {
            res += a[i];
        }

        printf("%lld\n", res);
    }

    return 0;
}
