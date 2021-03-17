#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;

    while (n--)
    {
        bool found = false;
        cin >> s;

        int count[10] = {0};

        for (auto x : s)
        {
            ++count[x - '0'];
        }

        for (auto x : count)
        {
            if (x >= 4)
            {
                cout << "Ronde!" << endl;
                found = true;
                break;
            }
        }

        if (found)
        {
            continue;
        }

        auto last = s[0];
        auto cou = 1;

        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == last)
            {
                ++cou;
                if (cou == 3)
                {
                    cout << "Ronde!" << endl;
                    found = true;
                    break;
                }
            }
            else
            {
                last = s[i];
                cou = 1;
            }
        }

        if (found)
        {
            continue;
        }

        found = true;
        for (int i = 0; i < s.size() / 2; ++i)
        {
            if (s[i] != s[s.size() - i - 1])
            {
                found = false;
            }
        }

        if (found)
        {
            cout << "Ronde!" << endl;
        }
        else
        {
            cout << "Rond Nist" << endl;
        }
    }

    return 0;
}
