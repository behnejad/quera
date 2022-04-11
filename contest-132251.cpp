#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    bool b = false;
    for (int i = 0; i < 5; ++i)
    {
        cin >> s;
        if (s.find("FBI") != string::npos)
        {
            b = true;
            cout << i + 1 << " ";
        }
    }
    if (!b)
    {
        cout << "HE GOT AWAY!" << endl;
    }
    return 0;
}
