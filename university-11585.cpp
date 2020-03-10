#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    long n = 0, t = 0, res = 0;
    vector<long> inputs;

    cin >> n;
    inputs.resize(n);

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    generate(inputs.begin(), inputs.end(), [&]() {cin >> t; return t;});
/*
    for (int i = 0; i < n; ++i)
    {
        long k = 0;
        for (int j = i; j < n; ++j)
        {
            cout << i + 1 << " " << j + 1 << " -> " << k << endl;
            res += accumulate(inputs.begin() + i, inputs.begin() + j + 1, 0);
        }
    }
*/

/*
    for (int i = 0; i < n; ++i)
    {
        long k = 0;
        for (int j = i; j < n; ++j)
        {
            k += inputs.at(j);
            res += k;
        }
    }

*/

    if (n == 1)
    {
        res = 1;
    }
    else
    {
        int len = inputs.size() >> 1;
        for (int i = 0; i < len; ++i)
        {
            res += (inputs.at(i) + inputs.at(n - i - 1)) * (i + 1) * (n - i);
        }
        if (inputs.size() & 1)
        {
            res += inputs.at(len) * (len + 1) * (n - len);
        }
    }

    cout << res << endl;

    return 0;
}
