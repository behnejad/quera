#include <iostream>
#include <cmath>

using namespace std;

double r, h, k;
int x1, y1, x2, y2, x3, y3;

void findCircle()
{
    int x12 = x1 - x2;
    int x13 = x1 - x3;

    int y12 = y1 - y2;
    int y13 = y1 - y3;

    int y31 = y3 - y1;
    int y21 = y2 - y1;

    int x31 = x3 - x1;
    int x21 = x2 - x1;

    int sx13 = pow(x1, 2) - pow(x3, 2);
    int sy13 = pow(y1, 2) - pow(y3, 2);

    int sx21 = pow(x2, 2) - pow(x1, 2);
    int sy21 = pow(y2, 2) - pow(y1, 2);

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



    return 0;
}
