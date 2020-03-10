#include <iostream>

using namespace std;

int main()
{
    long i;
    cin >> i;
    if (i == 1)
    {
        cout << "*" << endl;
    }
    else if (i == 2)
    {
        cout << "**" << endl << "**" << endl;
    }
    else
    {
        for (int j = 0; j < i; ++j)
        {
            cout << "*";
        }
        cout << endl;
        for (int j = 0;j < i - 2; ++j)
        {
            cout << "*";
            for (int k = 0; k < i - 2; ++k)
            {
                cout << " ";
            }
            cout << "*" << endl;
        }
        for (int j = 0; j < i; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
