#include <iostream>
#include <limits>

using namespace std;

int main()
{
    long i, j;
    cin >> i;
    long max = numeric_limits<long>::min();
    while (i > 0)
    {
        cin >> j;
        if (max < j)
        {
            max = j;
        }
        --i;
    }

    cout << max << endl;
    return 0;
}
