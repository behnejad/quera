#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool is_prime(int n)
{
    int m = sqrt(n);
    if ((m * m) == n)
        return false;
    else
        ++m;

    for (int i = 2; i < m; ++i)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool rebase_mirror(int n, int base)
{
    char digits[40];
    int len = 0;
    while (n != 0)
    {
        digits[len++] = n % base;
        n /= base;
    }

    if (len == 2)
    {
        return digits[0] == digits[1];
    }

    int index = len >> 1;
    --len;

    for (int i = 0; i < index; ++i)
    {
        if (digits[i] != digits[len - i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);

    for (int x : primes)
    {
        if (rebase_mirror(x, k))
        {
            --n;
            if (n == 0)
            {
                cout << x << endl;
                return 0;
            }
        }
    }

    for (int i = 10; i <= 5000000; ++i)
    {
        int m = sqrt(i);
        for (int x : primes)
        {
            if (x > m)
            {
                if (rebase_mirror(i, k))
                {
                    --n;
                    if (n == 0)
                    {
                        cout << i << endl;
                        return 0;
                    }
                }
                primes.push_back(i);
                break;
            }
            else if (i % x == 0)
            {
                break;
            }
        }
    }

    cout << "done" << endl;

    return 0;
}
