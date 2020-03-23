#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (a > b)
    {
        swap(a, b);
    }
    if (d > e)
    {
        swap(d, e);
    }
    if (e > f)
    {
        swap(e, f);
    }
    if (d > e)
    {
        swap(d, e);
    }
    if ((a >= d && b >= e) || (a >= e && b >= f) || (a >= f && b >= d))
    {
        cout << "zende mimuni" << endl;
    }
    else
    {
        cout << "dari mimiri" << endl;
    }
    return 0;
}
