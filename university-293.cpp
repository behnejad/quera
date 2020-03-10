#include <iostream>
#include <string>

using namespace std;

void prime(long i)
{
    if (i == 1)
        return;

    if (i == 2)
    {
        cout << i << endl;
        return;
    }

    long t = i - 1;
    while (t > 1)
    {
        if ((i % t) == 0)
        {
            return;
        }
        --t;
    }
    cout << i << endl;
}

int main()
{
    long i, j;
    cin >> i >> j;

    while (i <= j)
    {
        prime(i);
        ++i;
    }

    return 0;
}
