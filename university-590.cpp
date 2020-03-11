#include <iostream>

using namespace std;

int main()
{
    long a, b, aa, bb, bmm;
    cin >> a >> b;
    aa = a;
    bb = b;

    bmm = b % a;
    while (bmm != 0)
    {
        b = a;
        a = bmm;
        bmm = b % a;
    }



    cout << a << " " << aa * bb / a << endl;

    return 0;
}
