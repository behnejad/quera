#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long z;
    cin >> z;
    if (z % 2 == 1)
    {
        cout << "No" << endl;
    }
    else
    {
        long double res = log2((long double) z);
        if ((long long) res == res)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
