#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long a, b, aa, bb, bmm;
    string aaa, bbb;
    cin >> aaa >> bbb;

    a = stoll(aaa);
    b = stoll(bbb);

    aa = a;
    bb = b;

    bmm = b % a;
    while (bmm != 0)
    {
        b = a;
        a = bmm;
        bmm = b % a;
    }

    cout << a << endl;

    return 0;
}
