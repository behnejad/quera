#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string a, b;

    while (n--)
    {
        cin >> a >> b;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                ++j;
            }
            ++i;
        }

        if (j == b.size())
        {
            cout << "YES" << endl;
            continue;
        }

        i = 0;
        j = 0;
        reverse(a.begin(), a.end());

        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                ++j;
            }
            ++i;
        }

        if (j == b.size())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }


    return 0;
}
