#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    int n, t;
    cin >> n;
    vector<int> a(n);
    generate(a.begin(), a.end(), [&]() {cin >> t; return t;});
    long max = numeric_limits<long>::min();
    long sum;

    for (int i = 0; i < n; ++i)
    {
        sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += a[j];
            if (max < sum)
            {
                max = sum;
            }
        }
    }

    cout << (max > 0 ? max : 0) << endl;

    return 0;
}
