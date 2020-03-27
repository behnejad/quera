#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int i = 0;
    while (i < s.size())
    {
        if (s[i] != '0')
        {
            break;
        }
        ++i;
    }
    cout << (i != s.size() ? s.c_str() + i : "0") << endl;
    return 0;
}
