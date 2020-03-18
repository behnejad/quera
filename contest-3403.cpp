#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    double mini, maxi, sum, avg, product;
    mini = min(a, min(b, min(c, d)));
    maxi = max(a, max(b, max(c, d)));
    sum = a + b + c + d;
    avg = sum * 1.0 / 4;
    product = a * b * c * d;

    cout << fixed << setprecision(6) <<
            "Sum : " << sum << endl <<
            "Average : " << avg << endl <<
            "Product : " << product << endl <<
            "MAX : " << maxi << endl <<
            "MIN : " << mini << endl;

    return 0;
}
