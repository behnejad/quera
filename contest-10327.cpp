#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    string t, org;
    cin >> n >> t;
    org = t;
    set<char> alphabet;
    set<string> used;
    for (char x : t)
    {
        alphabet.insert(x);
    }

    while (n--)
    {
        t.clear();
        cin >> t;
        if (t == org || used.count(t) != 0)
        {
            cout << "No" << endl;
        }
        else
        {
            bool boo = true;
            for (int i = 0; i < t.size() && boo; ++i)
            {
                if (alphabet.count(t[i]) == 0)
                {
                    boo = false;
                }
            }
            cout << (boo ? "Yes" : "No") << endl;
        }
        used.insert(t);
    }

    return 0;
}
