#include <iostream>
#include <queue>

using namespace std;

int main()
{
    long long n, q, t, k;
    cin >> n >> q;
    queue<long long> array[n];
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> t;
            for (queue<long long> & i : array)
            {
                i.push(t);
            }
        }
        else if (t == 2)
        {
            cin >> t >> k;
            n = 0;
            while (k--)
            {
                n += array[t - 1].front();
                array[t - 1].pop();
            }
            cout << n << endl;
        }
    }
    return 0;
}
