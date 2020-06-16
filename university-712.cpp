#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;

    int * a = new int[n];
    for (int i = 1; i <= n; ++i)
    {
        a[i - 1] = i;
    }

    char temp[30];
    string s;

    while (t--)
    {
        cin >> s;
        if (s == "NAME")
        {
            int i;
            cin >> i;
            cout << a[i - 1] << endl;
        }
        else if (s == "REV")
        {
            int start, end;
            cin >> start >> end;
            reverse(a + start - 1, a + end);
        }
    }

    delete[] a;
    return 0;
}
