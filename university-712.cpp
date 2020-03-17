#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> a;
    for (int i = 1; i <= n; ++i)
    {
        a.push_back(i);
    }

    while (t--)
    {
        string s;
        cin >> s;
        if (s == "NAME")
        {
            int i;
            cin >> i;
            cout << a[i - 1] << endl;
        }
        else if (s == "REV")
        {
            int i, j;
            cin >> i >> j;
            reverse(a.begin() + i - 1, a.begin() + j - 1);
        }
    }

    return 0;
}
