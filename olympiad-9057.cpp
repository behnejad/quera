#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main()
{
    int n;
    cin >> n;

    vector<ull> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int q;
    cin >> q;

    while (q--)
    {
        int s, k;
        cin >> s >> k;
        ull j = 0;

        int u = (n - s) / k;
        for (int i = 1; i <= u; ++i)
        {
            j += a[s + (i * k) - 1];
        }

        cout << j << endl;
    }


    return 0;
}
