#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    cout << (a[0] == b[b.length() - 1] ? "YES" : "NO") << endl;
    return 0;
}
