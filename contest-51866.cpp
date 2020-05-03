#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> a;
vector<int> scores;
int total_min = numeric_limits<int>::max();

void find(int index, int n, int i, int k)
{
    if (i == k)
    {
        int all_min = numeric_limits<int>::max();
        int c = 0;
        for (int j = 0; j < k; ++j)
        {
            int set_max = numeric_limits<int>::min();
            for (int m = 0; m < scores[j]; ++m)
            {
                if (set_max < a[c])
                {
                    set_max = a[c];
                }

                ++c;
            }

            if (all_min > set_max)
            {
                all_min = set_max;
            }
        }

        if (all_min < total_min)
        {
            total_min = all_min;
        }
    }
    else if (i == k - 1)
    {
        scores[i] = n - index;
        find(0, n, i + 1, k);
    }
    else
    {
        for (int j = 0; j < n - index + k - i - 3; ++j)
        {
            scores[i] = j + 1;
            find(j + 1 + index, n, i + 1, k);
        }
    }
}

int main()
{
    int n, k;
    int max = numeric_limits<int>::min();
    int min = numeric_limits<int>::max();

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        a.push_back(t);

        if (max < t)
        {
            max = t;
        }
        if (min > t)
        {
            min = t;
        }
    }

    if (k == 1)
    {
        cout << max << endl;
    }
    else if (k == n || min == a[0] || min == a[n - 1])
    {
        cout << min << endl;
    }
    else
    {
        scores.resize(k);
        find(0, n, 0, k);
        cout << total_min << endl;
    }

    return 0;
}
