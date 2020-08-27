#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ull v;
    cin >> v;

    vector<ull> d;
    for (ull i = v; i > 0; --i)
    {
        if ((v % i) == 0)
        {
            d.push_back(i);
        }
    }

    ull min = numeric_limits<ull>::max();

    for (ull a : d)
    {
        for (ull b : d)
        {
            ull c = a * b;
            if ((v % c) == 0)
            {
                c = v / c;
                ull q = (a * b) + (a * c) + (b * c);
                if (q < min)
                {
                    min = q;
                }
            }
        }
    }

    cout << (min << 1) << endl;
    return 0;
}
