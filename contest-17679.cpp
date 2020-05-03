#include <iostream>
#include <queue>

using namespace std;

int main()
{
    unsigned long long n, q, i, j, x;
    cin >> n >> q;
    queue<unsigned long long> array[n];
    while (q--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> x;
            for (queue<unsigned long long> & i : array)
            {
                i.push(x);
            }
        }
        else if (x == 2)
        {
            cin >> i >> j;
            n = 0;
            --i;
            if (j != 0)
            {
                while (j-- && array[i].size())
                {
                    n += array[i].front();
                    array[i].pop();
                }
            }

            cout << n << endl;
        }
    }
    return 0;
}
