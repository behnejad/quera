#include <iostream>

using namespace std;

int main()
{
    char a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (a == b || c == d || a == d || b == c ? "YES" : "NO") << endl;
    return 0;
}
