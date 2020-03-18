#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, count = 0;
    cin >> i;
    string s, t;
    cin >> s >> t;
    while (i--)
    {
        if (s[i] != t[i])
        {
            ++count;
        }
    }
    cout << count << endl;
    return 0;
}
