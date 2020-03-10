#include <iostream>

using namespace std;

int main()
{
    long i;
    cin >> i;
    long j = 1;
    while (j < i)
    {
        j <<= 1;
    }
    cout << j << endl;
    return 0;
}
