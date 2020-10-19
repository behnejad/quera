#include <iostream>
#include <queue>
#include <vector>

using namespace std;



int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> legs;
    legs.resize(n, 2);
    queue<int> legs_queue;
    for (int i = 0; i < n; ++i)
    {
        legs_queue.push(i);
        legs_queue.push(i);
    }

    int p;
    while (true)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (legs[i] != 0)
            {
                p = i;
                ++sum;
            }
        }

        if (sum == 1)
        {
            cout << "winner:" << p + 1 << endl;
            break;
        }

        if (legs_queue.size() == 1)
        {
            cout << "winner:" << legs_queue.front() + 1 << endl;
            break;
        }

        for (int i = 0; i < k; ++i)
        {
            p = legs_queue.front();
            legs_queue.pop();
            cout << p + 1 << " ";
            if (i != k - 1)
            {
                legs_queue.push(p);
            }
            else
            {
                --legs[p];
            }
        }

        cout << endl;
    }

    return 0;
}
