#include <iostream>
#include <string>

using namespace std;

int main()
{
    char x;
    string a, b;
    cin >> a >> x >> b;
    if (x == '*')
    {
        int z = a.size() - 1 + b.size();
        a.resize(z, '0');
        cout << a << endl;
    }
    else if (x == '+')
    {
        if (a.size() == b.size())
        {
            a[0] += 1;
            cout << a << endl;
        }
        else
        {
            if (a.size() > b.size())
            {
                a[a.size() - b.size()] = '1';
                cout << a << endl;
            }
            else
            {
                b[b.size() - a.size()] = '1';
                cout << b << endl;
            }
        }
    }
    return 0;
}
