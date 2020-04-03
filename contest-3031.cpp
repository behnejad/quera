#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ull n, k, a, b;
    cin >> n >> k;
    vector<pair<bool, pair<ull, ull>>> array;

    while (n--)
    {
        cin >> a >> b;
        array.emplace_back(false, pair<ull, ull>(a, b));
    }

    while (true)
    {
        bool pick = false;

        for (pair<bool, pair<ull, ull>> & x : array)
        {
            if (x.first == false)
            {
                if (k >= x.second.first && (x.second.first < x.second.second))
                {
                    pick = true;
                    x.first = true;
                    k += x.second.second - x.second.first;
                }
            }
        }

        if (pick == false)
        {
            break;
        }
    }

    cout << k << endl;
    return 0;
}
