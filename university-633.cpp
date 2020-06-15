#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    ++n;
    vector<long> base(n), res(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> base[i];
        res[i] = base[i];
    }

    --m;
    while (m--)
    {
        vector<long> t(base.size() + res.size() - 1, 0);
        for (size_t i = 0; i < res.size(); ++i)
        {
            for (size_t j = 0; j < base.size(); ++j)
            {
                t[t.size() - (res.size() - i - 1 + base.size() - j - 1) - 1] += base[j] * res[i];
            }
        }

        res = move(t);
    }

    for (long x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
