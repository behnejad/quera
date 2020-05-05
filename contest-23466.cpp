#include <iostream>
#include <map>
#include <set>

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
            //merge
            for (map<int, myl>::iterator it = local.begin(); it != local.end(); ++it)
            {
                set<myl> ts;

            }


            local.clear();

            myl i = 0;
            for (map<int, set<myl>>::iterator it = types.begin(); it != types.end(); ++it)
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
