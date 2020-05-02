#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

int main()
{
    double ep = numeric_limits<double>::epsilon();
    double a, b, c;
    cin >> a >> b >> c;
    double x, y;

    if (fabs(a) < ep && fabs(b) < ep)
    {
        cout << "IMPOSSBILE" << endl;
    }
    else if (fabs(c) < ep && (fabs(a) < ep || fabs(b) < ep))
    {
        cout << "0.000" << endl;
    }
    else
    {
        if (fabs(a) < ep)
        {
            x = (-c) / b;
            cout << fixed << setprecision(3) << x << endl;
        }
        else
        {
            double qrt = (b * b) - (a * c * 4);
            if (qrt < 0.0)
            {
                cout << "IMPOSSIBLE" << endl;
            }
            else if (fabs(qrt) < ep)
            {
                x = ((-b) / a) / 2;
                cout << fixed << setprecision(3) << x << endl;
            }
            else if (fabs(sqrt(qrt)) < ep)
            {
                x = ((-b) / a) / 2;
                cout << fixed << setprecision(3) << x << endl;
            }
            else
            {
                x = ((-b) - sqrt(qrt)) / (a * 2);
                y = ((-b) + sqrt(qrt)) / (a * 2);
                if (x < y)
                {
                    cout << fixed << setprecision(3) << x << endl
                         << fixed << setprecision(3) << y << endl;
                }
                else
                {
                    cout << fixed << setprecision(3) << y << endl
                         << fixed << setprecision(3) << x << endl;
                }
            }
        }
    }


    return 0;
}
