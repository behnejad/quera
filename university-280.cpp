#include <iostream>
#include <numeric>


using namespace std;

int main()
{
    long a, b, c, t;
    cin >> a >> b >> c;
    if (a > b)
    {
        swap(a, b);
    }
    if (b > c)
    {
        swap(b, c);
    }
    cout << ((((a * a) + (b * b)) == (c * c)) ? "YES" : "NO") << endl;
    return 0;
}
