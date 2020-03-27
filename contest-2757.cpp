#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> primes;
    int i = 2;
    while (n != 1)
    {
        if (n % i == 0)
        {
            primes.insert(i);
            n /= i;

            while (n % i == 0)
            {
                n /= i;
            }
        }

        ++i;
    }

    long long res = 1;
    for (auto i : primes)
    {
        res *= i;
    }

    cout << res << endl;

    return 0;
}
