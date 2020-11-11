#include <iostream>

using namespace std;

int main()
{
    string s;
    int n, m, a = 0, b = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        for (char x : s)
        {
            if (x == '*')
            {
                ++a;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        for (char x : s)
        {
            if (x == '*')
            {
                ++b;
            }
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
