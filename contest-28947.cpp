#include <iostream>
#include<string>

using namespace std;

int main()
{
    int m;
    cin >> m;
    string s;
    while (m--)
    {
        s.resize(m + 1, 's');
        cout << s << endl;
    }
    return 0;
}
