#include <iostream>

using namespace std;

int main()
{
    long long neg = 0, posi = 0, n;
    cin >> n;
    while (n--)
    {
        long long i;
        cin >> i;
        if (i < 0)
        {
            ++neg;
        }
        else
        {
            ++posi;
        }
    }

    cout << neg * (posi + neg - 1) << endl;
    return 0;
}
