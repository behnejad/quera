#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main1()
{
    long count = 0;
    int n, p;
    cin >> n;

    if (n <= 2)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> t;

    while (n--)
    {
        cin >> p;
        t.push_back(p);
    }

    for (int i = 1; i < t.size(); ++i)
    {


    }

    /*

    vector<pair<int, int>> ti;
    int local_max = t[0];
    bool last_push = true;

    for (int i = 1; i < t.size(); ++i)
    {
        if (local_max < t[i])
        {
            local_max = t[i];
        }
        if (local_max == t[i])
        {
            last_push = true;
        }
        else
        {
            if (last_push)
            {
                ti.push_back(make_pair(i, local_max));
                last_push = false;
            }
        }
    }

    bool last_step = false;

    for (int i = 0; i < ti.size(); ++i)
    {
        cout << ti[i].first << "\t" << ti[i].second << endl;

        bool start_count = false;
        for (int j = ti[i].first; j < t.size(); ++j)
        {
            if (t[j] >= ti[i].second)
            {
                start_count = true;
                break;
            }
        }

        if (start_count)
        {
            for (int j = ti[i].first; j < t.size(); ++j)
            {
                if (t[j] > ti[i].second)
                {
                    break;
                }

                count += (ti[i].second - t[j]);
            }
        } else if (i == ti.size() - 1)
        {
            last_step = true;
        }
    }

    if (last_step)
    {

    }
    */
    cout << count << endl;
    return 0;
}
