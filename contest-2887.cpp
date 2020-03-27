#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    auto * items = new unsigned long long[n];
    vector<unsigned long long> j;
    unsigned long long min = numeric_limits<unsigned long long>::max(), sum = 0, t;

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        if (min > t)
        {
            min = t;
        }
        items[i] = t;
    }

    if (min != 1)
    {
        t = 2;
        while (t <= min)
        {
            if (min % t == 0)
            {
                j.push_back(t);
            }

            ++t;
        }

        for (auto i : j)
        {
            bool dividable = true;
            for (int k = 0; k < n && dividable; ++k)
            {
                if (items[k] % i != 0)
                {
                    dividable = false;
                }
            }

            if (dividable)
            {
                for (int k = 0; k < n; ++k)
                {
                    items[k] /= i;
                }
            }
        }
    }

    for (int k = 0; k < n; ++k)
    {
        sum += items[k];
    }

    cout << sum << endl;
    delete[] items;
    return 0;
}
