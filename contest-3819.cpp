#include <iostream>
#include <cmath>

using namespace std;

double r, h, k;

void findCircle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double x12 = x1 - x2;
    double x13 = x1 - x3;

    double y12 = y1 - y2;
    double y13 = y1 - y3;

    double y31 = y3 - y1;
    double y21 = y2 - y1;

    double x31 = x3 - x1;
    double x21 = x2 - x1;

    double sx13 = pow(x1, 2) - pow(x3, 2);
    double sy13 = pow(y1, 2) - pow(y3, 2);

    double sx21 = pow(x2, 2) - pow(x1, 2);
    double sy21 = pow(y2, 2) - pow(y1, 2);

    double f = ((sx13) * (x12)
             + (sy13) * (x12)
             + (sx21) * (x13)
             + (sy21) * (x13))
            / (2 * ((y31) * (x12) - (y21) * (x13)));
    double g = ((sx13) * (y12)
             + (sy13) * (y12)
             + (sx21) * (y13)
             + (sy21) * (y13))
            / (2 * ((x31) * (y12) - (x21) * (y13)));

    double c = -pow(x1, 2) - pow(y1, 2) - 2 * g * x1 - 2 * f * y1;

    h = -g;
    k = -f;
    double sqr_of_r = h * h + k * k - c;

    r = sqrt(sqr_of_r);
}

int main()
{
    int n;
    cin >> n;

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    n -= 3;

    findCircle(x1, y1, x2, y2, x3, y3);

    if ((h - (int)h) != 0 || (k - (int)k) != 0)
    {
        cout << "No Answer" << endl;
    }
    else
    {
        int x, y;

        while (n--)
        {
            cin >> x >> y;
            x -= h;
            y -= k;
            if (sqrt((x * x) + (y * y)) != r)
            {
                cout << "No Answer" << endl;
                return 0;
            }
        }

        cout << (int)h << " " << (int) k << endl;
    }

    return 0;
}
