#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int c = 0;
    for (auto x : s)
    {
        if (x == 'i' || x == 'o' || x == 'u' || x == 'e' || x == 'a')
            ++c;
    }
    cout << c << endl;
    return 0;
}
