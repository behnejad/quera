#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    if (s == "shanbe" || s == "doshanbe" || s == "chaharshanbe")
    {
        cout << "perspolis" << endl;
    }
    else if (s == "yekshanbe" || s == "seshanbe" || s == "panjshanbe")
    {
        cout << "bahman" << endl;
    }
    else
    {
        cout << "tatil" << endl;
    }
    return 0;
}
