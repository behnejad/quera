#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        int last, current;
        cin >> last >> current;
        int shib, shib2;
        bool jahat = false;
        bool force = false;
        if (last == current)
            shib = 0;
        else if (last < current)
        {
            jahat = true;
            shib = 1;
        }
        else
        {
            jahat = true;
            shib = -1;
        }

        for (int i = 2; i < n; ++i)
        {
            last = current;
            cin >> current;

            if (last == current)
                shib2 = 0;
            else if (last < current)
                shib2 = 1;
            else
                shib2 = -1;

            if (force && shib != shib2)
            {
                cout << "No" << endl;
                return 0;
            }

            if (jahat)
            {
                if (shib2 != 0 && shib != shib2)
                {
                    shib = shib2;
                    force = true;
                }
            }
            else
            {
                if (shib2 != 0)
                {
                    jahat = true;
                    shib = shib2;
                }
            }
        }

        cout << "Yes" << endl;
    }

    return 0;
}
