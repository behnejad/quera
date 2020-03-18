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
        cin >> t;
        for (int i = 0; i < t.size() && boo; ++i)
        {
            if (alphabet.find(t[i]) == alphabet.end())
            {
                boo = false;
                cout << "No" << endl;
            }
        }

        if (boo)
        {
            cout << "Yes" << endl;
        }
    }


    return 0;
}
