#include <iostream>
#include <cmath>

using namespace std;

long long area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2)));
}

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
   long long A = area (x1, y1, x2, y2, x3, y3);
   long long A1 = area (x, y, x2, y2, x3, y3);
   long long A2 = area (x1, y1, x, y, x3, y3);
   long long A3 = area (x1, y1, x2, y2, x, y);
   return (A == A1 + A2 + A3);
}

void job()
{
    int ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    cout << (isInside(ax, ay, bx, by, cx, cy, dx, dy) ? "YES" : "NO") << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        job();
    }
    return 0;
}
