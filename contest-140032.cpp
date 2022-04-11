#include <iostream>

using namespace std;

bool triangle(int a, int b, int c)
{
    return a + b > c && b + c > a && a + c > b;
}

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if (triangle(a, b, c) || triangle(a, b, d) || triangle(a, b, e) ||
            triangle(a, c, d) || triangle(a, c, e) || triangle(a, d, e) ||
            triangle(b, c, d) || triangle(b, c, e) || triangle(b, d, e) ||
            triangle(c, d, e) )
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
