#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (b >= a)
    {
        cout << "Wrong order!" << endl;
    }
    else if (((a - b) % 2) != 0)
    {
        cout << "Wrong difference!" << endl;
    }
    else
    {
        int w = (a - b) / 2;
        for (int i = 0; i < w; ++i)
        {
            for (int j = 0; j < a; ++j)
            {
                cout << "* ";
            }
            cout << endl;
        }

        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cout << "* ";
            }

            for (int j = 0; j < b; ++j)
            {
                cout << "  ";
            }

            for (int j = 0; j < w; ++j)
            {
                cout << "* ";
            }

            cout << endl;
        }

        for (int i = 0; i < w; ++i)
        {
            for (int j = 0; j < a; ++j)
            {
                cout << "* ";
            }
            cout << endl;
        }

    }
    return 0;
}
