#include <iostream>

using namespace std;

int main()
{
    long n;
    cin >> n;
    long i = 0, j = 0;
    int d = 0;
    while (--n)
    {
        switch(d)
        {
        case 0:
            if (i < 0)
            {
                i = -i;
            }
            ++i;
            d = 1;
            break;
        case 1:
            if (j < 0)
            {
                j = -j;
            }
            ++j;
            d = 2;
            break;
        case 2:
            i = -i;
            d = 3;
            break;
        case 3:
            j = -j;
            d = 0;
            break;
        }
    }

    cout << i << " " << j << endl;
    return 0;
}
