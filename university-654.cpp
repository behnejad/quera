#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n < 12)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        int a = n >> 1;
        vector<pair<int, long>> moraba;

        int i = 2;
        long j = i * i;
        while (i < a)
        {
            moraba.push_back(pair<int, long>(i, j));
            ++i;
            j = i * i;
        }

//        cout << moraba.size() << endl;
        for (unsigned long long i = 0; i < moraba.size(); ++i)
        {
            for (unsigned long long j = i; j < moraba.size(); ++j)
            {
                int t = moraba[i].second + moraba[j].second;
                if ((moraba[i].first + moraba[j].first + sqrt(t) == n))
                {
//                    cout << moraba[i].second << " " << moraba[j].second << " " << t << endl;
                    cout << moraba[i].first << " " << moraba[j].first << " " << sqrt(t) << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Impossible" << endl;

    return 0;
}
