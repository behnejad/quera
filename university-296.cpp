#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << "#" << endl;
    }
    else if (n == 3)
    {
        cout << "###" << endl << "###" << endl << "###" << endl;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            cout << "#";
        }
        cout << endl;

        for (int i = 1; i < n - 1; ++i)
        {
            cout << "#";

            if (i < n /2)
            {
                int k = 0;
                for (int j = 0; j < i - 1; ++j)
                {
                    ++k;
                    cout << " ";
                }
                ++k;
                cout << "#";
                for (int j = 0; j < (n - 2 * i) - 2; ++j)
                {
                    ++k;
                    cout << " ";
                }
                ++k;
                cout << "#";
                for (int j = 0; j < n - k - 2; ++j)
                {
                    cout << "#";
                }
            }
            else if (i == n/2)
            {
                for (int j = 1; j < n /2; ++j)
                {
                    cout << " ";
                }
                for (int j = n /2; j < n - 1; ++j)
                {
                    cout << "#";
                }
            }
            else
            {
                int k = 0;
                for (int j = 0; j < n - i - 2; ++j)
                {
                    ++k;
                    cout << " ";
                }
                ++k;
                cout << "#";
                int l = n/2 - k;
                for (int j = 0; j < 2 * l - 1; ++j)
                {
                    ++k;
                    cout << " ";
                }
                ++k;
                cout << "#";
                for (int j = 0; j < n - k - 2; ++j)
                {
                    cout << "#";
                }
            }

            cout << "#" << endl;
        }

        for (int i = 0; i < n; ++i)
        {
            cout << "#";
        }
        cout << endl;
    }
    return 0;
}
