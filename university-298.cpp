#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    map<long long, int> primes;

    long long i = 2;
    while (n != 1)
    {
        while ((n % i) != 0)
        {
            i = (i == 2) ? 3 : (i + 2);
        }

        n /= i;

        if (primes.find(i) != primes.end())
        {
            primes[i] += 1;
        }
        else
        {
            primes[i] = 1;
        }

        i = 2;
    }

    vector<string> out;
    for_each(primes.begin(), primes.end(), [&](pair<const long long int, int> & i) {
        stringstream s;
        s << i.first;
        if (i.second != 1)
        {
            s << "^" << i.second;
        }
        string res;
        s >> res;
        out.push_back(move(res));
    });

    if (out.size() == 1)
    {
        cout << out[0] << endl;
    }
    else
    {
        int i;
        for (i = 0; i < out.size() - 1; ++i)
        {
            cout << out[i] << "*";
        }
        cout << out[i] << endl;
    }

    return 0;
}
