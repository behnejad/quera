#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, ss;
    getline(cin, s);
    for (char x : s)
    {
        if (isalpha(x))
        {
            ss += tolower(x);
        }
        if (isdigit(x))
        {
            ss += x;
        }
    }

    int i = 0, j = ss.size() - 1;
    while (i <= j)
    {
        if (ss[i] != ss[j])
        {
            cout << "NO" << endl;
            return 0;
        }
        --j;
        ++i;
    }

    cout << "YES" << endl;

    return 0;
}
