#include <iostream>

using namespace std;

int main()
{
    int n, k;
    long total = 0;

    cin >> n >> k;
    total = n * k;

    while (n--)
    {
        int i;
        cin >> i;
        total -= i;
    }

    cout << (total / k) << endl;

    return 0;
}
