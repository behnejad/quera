#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    long i, j = 1;
    cin >> i;
    while (i > 0)
    {
        j *= i--;
    }
    cout << j << endl;
    return 0;
}
