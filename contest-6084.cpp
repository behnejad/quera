#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> array(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }

    vector<int> div;
    div.push_back(1);

    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            div.push_back(i);
        }
    }

    bool found = false;
    bool error = false;
    long long sum1, sum2;

    for (int d : div)
    {
        error = false;
        sum1 = accumulate(array.begin(), array.begin() + d, 0);

        int t = n / d;
        for (int k = 1; k < t; ++k)
        {
            sum2 = accumulate(array.begin() + (k * d), array.begin() + ((k + 1) * d), 0);
            if (sum2 != sum1)
            {
                error = true;
                break;
            }
        }

        if (error == false)
        {
            found = true;
            cout << t << endl;
            break;
        }
    }

    if (found == false)
    {
        cout << 1 << endl;
    }

    return 0;
}
