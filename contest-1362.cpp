#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    int n;
    cin >> n >> s;
    vector<int> path(n, 0);
    path[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        if (s[i] != 'T')
        {
            int a = 0, b = 0, c = 0;

            if (i > 0 && s[i - 1] != 'T')
            {
                a = path[i - 1];
            }

            if (i > 1 && s[i - 2] != 'T')
            {
                b = path[i - 2];
            }

            if (i > 2 && s[i - 3] != 'T')
            {
                c = path[i - 3];
            }

            path[i] = a + b + c;
        }
    }

    cout << path[n - 1] << endl;

    return 0;
}
