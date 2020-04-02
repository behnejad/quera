#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, b = 0;
    long long count = 0;

    cin >> n;
    queue<int> array, working, working2;

    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        array.push(t);
    }

    while (array.size() != 0)
    {
        int i = 0;
        while (i < 4 && array.size() != 0)
        {
            working.push(array.front());
            array.pop();
            ++i;
        }

        b = 4;
        ++count;
        while (working.size() != 0)
        {
            if (working.front() == 1)
            {
                --b;
            }
            else
            {
                array.push(working.front() - 1);
            }
            working.pop();
        }
    }

    cout << count << endl;
    return 0;
}
