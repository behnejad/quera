#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (char x : s)
    {
        cout << x << ": ";
        for (int i = 0; i < (x - '0'); ++i)
        {
            cout << x;
        }
        cout << endl;
    }
    return 0;
}
