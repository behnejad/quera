#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<long long, int>> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = -1;
    }

    int day = 1;
    int count = 0;
    int last = 0;
    bool loop = true;
    while (loop)
    {
        last = 0;
        count = 0;
        loop = false;

        while (last < n && a[last].second != -1)
        {
            ++last;
        }

        if (last == n)
        {
            break;
        }

        for (int i = last + 1; i < n; ++i)
        {
            if (a[i].second == -1)
            {
                if (a[last].first == a[i].first)
                {
                    ++count;
                }
                else if (count >= 2)
                {
                    ++count;
                    loop = true;
                    while (count)
                    {
                        if (a[last].second == -1)
                        {
                            a[last].second = day;
                            --count;
                        }
                        ++last;
                    }
                }
                else
                {
                    count = 0;
                    last = i;
                }
            }
        }

        if (count >= 2)
        {
            ++count;
            loop = true;
            while (count)
            {
                if (a[last].second == -1)
                {
                    a[last].second = day;
                    --count;
                }
                ++last;
            }
        }

        ++day;
    }

    for (pair<long long, int> & x : a)
    {
        cout << x.second << " ";
    }
    cout << endl;

    return 0;
}
