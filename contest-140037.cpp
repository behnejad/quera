#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s;
    for (int i = 1; s.length() <= 1401; ++i)
    {
        s += to_string(i);
    }
    int i;
    cin >> i;
    cout << s[i - 1] << endl;
    return 0;
}
