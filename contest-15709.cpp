#include <iostream>
#include <string>
#include <map>
#include <limits>

using namespace std;

int main()
{
    string have, want;
    getline(cin, have);
    getline(cin, want);

    map<char, int> hav_count, want_count;
    for (char x : have)
    {
        if (hav_count.count(x) == 0)
        {
            hav_count[x] = 1;
        }
        else
        {
            hav_count[x] += 1;
        }
    }

    for (char x : want)
    {
        if (want_count.count(x) == 0)
        {
            want_count[x] = 1;
        }
        else
        {
            want_count[x] += 1;
        }
    }

    int min = numeric_limits<int>::max();

    for (pair<char, int> x : want_count)
    {
        int r = hav_count[x.first] / x.second;
        if (r < min)
        {
            min = r;
        }
    }

    cout << min << endl;
    return 0;
}
