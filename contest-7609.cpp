#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char last = s[0];
    int count = 0;
    for (char x : s)
    {
        if (last == x)
        {
            ++count;
        }
        else
        {
            last = x;

            if (count & 1)
            {
                break;
            }
            else
            {
                count = 1;
            }
        }
    }
    cout << ((count % 2 == 0) ? "khoob" : "bad") << endl;
    return 0;
}
