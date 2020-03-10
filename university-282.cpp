#include <iostream>

using namespace std;

int main()
{
    long i;
    cin >> i;
    long j = 0, k;
    k = i;
    --i;
    while (i > 0)
    {
        if ((k % i) == 0)
        {
            j += i;
        }
        --i;
    }

    cout << ((j == k) ? "YES" : "NO") << endl;
    return 0;
}
