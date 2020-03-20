#include <iostream>
#include <string>

using namespace std;

int main()
{
    int l, r;
    cin >> l >> r;

    string s = "1", temp;
    while (s.size() < 100000)
    {
        temp = s;
        for (char & x : temp)
        {
            x = (x == '0') ? '1' : '0';
        }
        s += temp;
    }

    for (int i = l - 1; i < r; ++i)
    {
        cout << s[i];
    }

    cout << endl;

    return 0;
}
