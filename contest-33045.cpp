#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    int n;
    unsigned long long count = 0, sum = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        int j = sqrt(i);
        for (int k = 1; k <= j; ++k)
        {
            if (i % k == 0)
            {
                ++count;
                sum += k;
                if (i / k != k)
                {
                    ++count;
                    sum += i / k;
                }
            }
        }
    }

    cout << count << " " << sum << endl;
    return 0;
}
