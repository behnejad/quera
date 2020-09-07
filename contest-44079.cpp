#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days_arr[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

int get_mount(int day)
{
    for (int m = 11; m >= 0; --m)
    {
        if (day > days_arr[m])
        {
            return m;
        }
    }
    return 0;
}

int main()
{
    int oct27 = days_arr[9] + 27;
    int n, m, d;
    string temp;
    cin >> n;

    vector<pair<int, int>> day_dist(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> temp >> m >> d;
        d = -d;
        day_dist[i].first = days_arr[m - 1] + d;
    }

    sort(day_dist.begin(), day_dist.end());

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            day_dist[i].second = 365 - day_dist[n - 1].first + day_dist[0].first;
        }
        else
        {
            day_dist[i].second = day_dist[i].first - day_dist[i - 1].first;
        }
    }

    sort(day_dist.begin(), day_dist.end(), [=](const pair<int,int> &a, const pair<int,int> &b) {
        if (a.second > b.second)
        {
            return true;
        }
        else if (a.second == b.second)
        {
            return abs(a.first - oct27) < abs(b.first - oct27);
        }
        else
        {
            return false;
        }
    });

//    for (int i = 0; i < n; ++i)
//    {
//        cout << day_dist[i].first << "\t" << day_dist[i].second << endl;
//    }

    for (pair<int, int> & a : day_dist)
    {
        int df = a.first - 1;
        if (df == 0)
            df = 365;
        int mf = get_mount(df);
        cout << setfill('0') << setw(2) << mf + 1 << "-"
             << setfill('0') << setw(2) << df - days_arr[mf] << endl;
        return 0;
    }

    return 0;
}
