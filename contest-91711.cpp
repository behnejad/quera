#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> ar(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> ar[i];
    }

    sort(ar.begin(), ar.end());

    while (ar[0] >= x)
    {
        bool change = false;
        for (int i = 1; i < n; ++i)
        {
            if (ar[i] < 100)
            {
                ar[0] -= x;
                ar[i] += y;
                change = true;
            }
        }

        if (change == false)
        {
            break;
        }
    }

    for (int i = 1; i < n; ++i)
    {
        if (ar[i] < 100)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
