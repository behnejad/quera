#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    string t;
    cin >> n >> t;
    set<char> alphabet;
    for (char x : t)
    {
        alphabet.insert(x);
    }

    while (n--)
    {
        bool boo = true;
        t.clear();
        cin >> t;
        for (int i = 0; i < t.size() && boo; ++i)
        {
            if (alphabet.count(t[i]) == 0)
            {
                boo = false;
            }
        }

        cout << (boo ? "Yes" : "No") << endl;
    }


    return 0;
}
