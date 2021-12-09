#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;

int main()
{
    string type;
    int n, p, r;
    cin >> n;
    vector<pair<int, int>> lamps(n); // <power, switch time>

    for (int i = 0; i < n; ++i)
    {
        cin >> type >> lamps[i].first;
        if (type == "SENSOR")
        {
            cin >> lamps[i].second;
        }
        else
        {
            lamps[i].second = 0;
        }
    }

    cin >> p;
    vector<pair<ull, ull>> table(p); // <cap, price>

    for (int i = 0; i < p; ++i)
    {
        cin >> table[i].first >> table[i].second;
    }

    cin >> r;
    int id, d, h, m, s;
    char ct;

    unordered_map<int, vector<int>> sw;
    unordered_map<int, vector<pair<int, int>>> swt;

    for (int i = 0; i < r; ++i)
    {
        cin >> id >> d >> h >> ct >> m >> ct >> s;
        int secs = (d * 24 * 3600) + (h * 3600) + (m * 60) + s;
        --id;
        if (lamps[id].second == 0)
        {
            sw[id].push_back(secs);
        }
        else
        {
            int last = secs + lamps[id].second;
            last = (last >= 32*24*3600) ? (32 * 24 * 3600) : last;

            if (swt[id].size() != 0)
            {
                if (swt[id].back().second >= secs)
                {
                    swt[id].back().second = last;
                }
                else
                {
                    swt[id].push_back(make_pair(secs, last));
                }
            }
            else
            {
                swt[id].push_back(make_pair(secs, last));
            }
        }
    }

    ull swi = 0;
    for (auto & x : sw)
    {
        if (x.second.size() % 2)
        {
            x.second.push_back((32 * 24 * 3600) - 1);
        }

        for (auto i = 0; i < x.second.size(); i += 2)
        {
            // cout << "power " << x.first << ": " << x.second[i + 1] - x.second[i] << " " << lamps[x.first].first << endl;
            swi += lamps[x.first].first * (x.second[i + 1] - x.second[i]);
        }
    }

//    cout << "swi: " << swi << endl;

    for (auto & x : swt)
    {
        auto p = lamps[x.first].first;
        for (auto & z : x.second)
        {
//            cout << "power " << x.first << ": " << z.second - z.first << " " << p << endl;
            swi += p * (z.second - z.first);
        }
    }

//    cout << "swi: " << swi << endl;

    ull price = 0;
    for (auto & x : table)
    {
        if (x.first >= swi)
        {
            price += swi * x.second;
            break;
        }
    }

    cout << price << endl;
    return 0;
}
