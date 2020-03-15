#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    int n, j;
    cin >> n;
    vector<int> in;

    while (n--)
    {
        cin >> j;
        in.push_back(j);
    }

    long long end = 0;

    for (int i = 0; i < in.size(); ++i)
    {
        for (int j = i + 1; j < in.size(); ++j)
        {
            end += (in[i] * in [j]) << 1;
        }
    }

    for (long i = 100; i <= end; ++i)
    {
        string j = to_string(i);
        long k = accumulate(j.begin(), j.end(), 0, [&](int & o, char & m){
            return o + (long)(pow(m - '0', j.size()));
        });

        if (k == i)
        {
            cout << i << endl;
        }
    }

    return 0;
}
