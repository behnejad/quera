#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int main()
{
    long long n, temp;
    int c;
    cin >> n >> c;

    if (n == 1)
    {
        while (c--)
        {
            cin >> temp;
            if (temp == 0)
            {
                cout << 1 << endl;
            }
        }

        return 0;
    }

    deque<pair<bool, long long>> q;
    temp = min(n, 1000ll);

    while (temp)
    {
        q.emplace_front(true, temp--);
    }

    while (c--)
    {
        cin >> temp;

        if (temp == 0)
        {
            while (q.front().first == false)
            {
                q.pop_front();
            }

            cout << q.front().second << endl;

            if (n <= 1000)
            {
                q.push_back(q.front());
            }

            q.pop_front();
        }
        else
        {
            bool found = false;
            for (size_t i = 0; i < q.size(); ++i)
            {
                if (q[i].second == temp && q[i].first)
                {
                    q[i].first = false;
                    q.emplace_front(true, temp);
                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                q.emplace_front(true, temp);
            }
        }
    }

    return 0;
}
