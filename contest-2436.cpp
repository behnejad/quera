#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, h, v, t;
    long long hmax = 0, hlocal;
    vector<pair<long long, long long>> ski;
    cin >> n >> m;
    while (n--)
    {
        cin >> h >> v;
        ski.emplace_back(v, h);
    }

    while (m--)
    {
        cin >> t;
        for (int i = 0; i < ski.size(); ++i)
        {
            hlocal = ski[i].first * t + ski[i].second;
            if (hlocal > hmax)
            {
                hmax = hlocal;
            }
        }

        cout << hmax << " ";
    }
    cout << endl;
    return 0;
}
