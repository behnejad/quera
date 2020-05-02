#include <iostream>

using namespace std;

int main()
{
    int n, t;
    cin >> n;
    while (n--)
    {
        cin >> t;
        switch(t)
        {
        case 2:
            cout << "**" << endl;
            break;
        case 3:
            cout << "***" << endl;
            break;
        default:
            cout << "*" << endl;
            break;
        }
    }
    return 0;
}
