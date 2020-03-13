#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    long double a, b, c;
    cin >> a >> b >> c;
    long double x, y;

    cout << fixed << setprecision(3);

    if (a == 0 && b == 0)
    {
        cout << "IMPOSSBILE" << endl;
    }
    else if ((a == 0 && c == 0) || (b == 0 && c == 0))
    {
        cout << "0.000" << endl;
    }
    else
    {
        if (a == 0)
        {
            x = (-c) / b;
            cout << x << endl;
        }
        else
        {
            long double qrt = (b * b) - ((a * c) * 4);
            if (qrt < 0)
            {
                cout << "IMPOSSIBLE" << endl;
            }
            else if (qrt == 0)
            {
                x = (-b) / (a * 2);
                cout << x << endl;
            }
            else
            {
                x = ((-b) - sqrtl(qrt)) / (a * 2);
                y = ((-b) + sqrtl(qrt)) / (a * 2);
                cout << x << endl << y << endl;
            }
        }
    }

    return 0;
}
