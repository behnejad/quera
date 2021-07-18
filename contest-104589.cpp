#include <iostream>

using namespace std;

int main()
{
    int i;
    cin >> i;
    int kmin = 1;
    for (auto j = 2; j <= i; ++j)
    {
        if ((i % j) == 0)
        {
            kmin = j;
            break;
        }
    }

    cout << i / kmin << endl;

    return 0;
}
