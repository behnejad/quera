#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    if (n == 1)
    {
        cout << "copy of " << s << endl;
    }
    else
    {
        while (n--)
        {
            cout << "copy of ";
        }
        cout << s << endl;
    }

    return 0;
}
