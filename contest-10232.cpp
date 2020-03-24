#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, l, t = 0, d = 0;
    cin >> n >> l;
    vector<int> lights_distance;
    vector<pair<int, int>> lights_cycles;

    while (n--)
    {
        int di, ri, gi;
        cin >> di >> ri >> gi;
        lights_distance.push_back(di);
        lights_cycles.emplace_back(ri, gi);
    }

    for (int i = 0; i < lights_distance.size(); ++i)
    {
        t += (lights_distance[i] - d);
        d = lights_distance[i];
        int period = lights_cycles[i].first + lights_cycles[i].second;
        int curent = t % period;
        if (curent < lights_cycles[i].first)
        {
            t += lights_cycles[i].first - curent;
        }
    }
    if (d != l)
    {
        t += l - d;
    }
    cout << t << endl;
    return 0;
}
