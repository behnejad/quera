#include <iostream>
#include <string>

using namespace std;

bool is_prime(long i)
{
    if (i < 2)
    {
        return false;
    }
    else if (i == 2)
    {
        return true;
    }
    else
    {
        long t = i - 1;
        while (t > 1)
        {
            if (i % t == 0)
            {
                return false;
            }
            --t;
        }
        return true;
    }
}

int main()
{
    long i, n, org;
    cin >> i;
    org = i;
    n = 0;

    while (i > 0)
    {
        n += (i % 10);
        i /= 10;
    }

    while (n > 0)
    {
        if (is_prime(++org))
        {
            --n;
        }
    }

    cout << org << endl;

    return 0;
}
