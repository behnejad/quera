#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a1, a2, a3;
    int b1, b2, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    cout << min(a1, b1) + min(a2, b2) + min(a3, b3) << endl;
    return 0;
}
