#include <iostream>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define e97 1000000007
typedef unsigned long long myl;

int main()
{
    myl n, c, t;
    char q;
    cin >> n;

    map<int, set<myl>> types;
    map<int, myl> local;

    while (n--)
    {
        cin >> q;

        if (q == '?')
        {
            map<int, myl>::iterator last1 = local.end();
            for (map<int, myl>::iterator it = local.begin(); it != last1; ++it)
            {
                if (types.count(it->first) == 0)
                {
                    types[it->first] = set<myl>();
                    myl j = sqrtl(it->second), t;

                    for (myl k = 1; k <= j; ++k)
                    {
                        if (it->second % k == 0)
                        {
                            types[it->first].insert(k);
                            t = it->second / k;
                            if (t != k)
                            {
                                types[it->first].insert(t);
                            }
                        }
                    }
                }
                else
                {
                    set<myl> temp = types[it->first];
                    for (myl x : temp)
                    {
                        if ((it->second % x) != 0)
                        {
                            types[it->first].erase(x);
                        }
                    }
                }
            }


            local.clear();

            myl i = 1;
            map<int, set<myl>>::iterator last = types.end();
            for (map<int, set<myl>>::iterator it = types.begin(); it != last; ++it)
            {
                i *= (it->second.size() % e97);
                i %= e97;
            }

            cout << i << endl;
        }
        else if (q == '+')
        {
            cin >> c >> t;

            if (local.count(t))
            {
                local[t] += c;
            }
            else
            {
                local[t] = c;
            }
        }
    }

    return 0;
}
