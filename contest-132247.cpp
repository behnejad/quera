#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    string x;
    unordered_map<string, int> s;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (s.find(x) == s.end())
        {
            s[x] = 1;
        }
        else
        {
            s[x] += 1;
        }
    }

    --n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        auto & c = s[x];
        if (c == 1)
        {
            s.erase(x);
        }
        else
        {
            c -= 1;
        }
    }

    cout << s.begin()->first << endl;

    return 0;
}
