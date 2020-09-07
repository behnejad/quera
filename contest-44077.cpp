#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double s = a + b + c + d;
    s /= 2.0;
    double t = (s - a) * (s - b) * (s - c) * (s - d);
    t = sqrt(t);
    cout.precision(17);
    cout << t << endl;
    return 0;
}
