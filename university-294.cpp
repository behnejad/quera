#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    float x, y;

    if (a == 0 && b == 0)
    {
        cout << "IMPOSSBILE" << endl;
    }
    else if (c == 0 && (a == 0 || b == 0))
    {
        cout << "0.000" << endl;
    }
    else
    {
        if (a == 0)
        {
            x = (-c) / b;
            cout << fixed << setprecision(3) << x << endl;
        }
        else
        {
            float qrt = (b * b) - (a * c * 4);
            if (qrt < 0)
            {
                cout << "IMPOSSIBLE" << endl;
            }
            else if (qrt == 0)
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
