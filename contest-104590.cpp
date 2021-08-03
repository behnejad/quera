#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> dots(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> dots[i].first;
    }

    if (dots[0].first != dots[1].first)
    {
        dots[0].second = dots[1].second = 1;
    }
    else
    {
        dots[0].second = 1;
        dots[1].second = 2;
    }

    for (int i = 2; i < n; ++i)
    {
        if (dots[i].first != dots[i - 1].first)
        {
            dots[i].second = dots[i - 1].second;
        }
        else
        {
            dots[i].second = dots[i - 1].second + 1;
        }
    }

    while (q--)
    {
        int i, j;
        cin >> i >> j;
        --i;
        --j;

        cout << (dots[i].second == dots[j].second ? "YES" : "NO") << endl;
    }

    return 0;
}
