#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    long n, q, t;
    cin >> n >> q;

    vector<long> inputs(n);
    generate(inputs.begin(), inputs.end(), [&]() {cin >> t; return t;});

    unordered_map<long, long> results;

    for (int i = 0; i < q; ++i)
    {
        cin >> t;
        long res = 0;
        if (results.count(t))
        {
            res = results[t];
        }
        else
        {

            for (long j = 0; j < t; ++j)
            {
                res += inputs.at(j) ^ (t - j - 1);
            }
            results[t] = res;
        }
        cout << res << endl;
    }

    return 0;
}
