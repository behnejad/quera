#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<unsigned long long> a(n);
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
        unsigned long long j = 0;

        int u = (n - s) / k;
        for (int i = 1; i <= u; ++i)
        {
            j += a[s + (i * k) - 1];
        }

        cout << j << endl;
    }


    return 0;
}
