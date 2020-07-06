#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int prime_number[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int main()
{
    int n, t;
    cin >> n;

    map<int, int> primes;

    while (n--)
    {
        cin >> t;
        if (t != 1)
        {
            while (t != 1)
            {
                for (int x : prime_number)
                {
                    if (x > t)
                        break;

                    if (t % x == 0)
                    {
                        int count = 0;
                        do
                        {
                            ++count;
                            t /= x;
                        } while (t % x == 0);

                        if (primes.count(x) == 0 || primes[x] < count)
                        {
                            primes[x] = count;
                        }
                    }
                }
            }
        }
    }

    t = 1;
    for (pair<int, int> x : primes)
    {
        for (int i = 0; i < x.second; ++i)
        {
            t *= x.first;
        }
    }

    cout << (t % 30) + 1 << endl;

    return 0;
}
