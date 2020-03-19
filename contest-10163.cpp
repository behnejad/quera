#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int a, b, c;
    int x1, x2, x3;
    int y1, y2, y3;
    int minx, maxy;
    cin >> a >> b >> c;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    minx = min(x1, min(x2, x3));
    maxy = max(y1, max(y2, y3));
    vector<int> t(maxy - minx, 0);
    x1 -= minx;
    x2 -= minx;
    x3 -= minx;
    y1 -= minx;
    y2 -= minx;
    y3 -= minx;
    for (int i = x1; i < y1; ++i)
    {
        t[i] += 1;
    }
    for (int i = x2; i < y2; ++i)
    {
        t[i] += 1;
    }
    for (int i = x3; i < y3; ++i)
    {
        t[i] += 1;
    }

    cout << accumulate(t.begin(), t.end(), 0, [&](long i, int j){
        if (j == 1)
        {
            return i + (a * j);
        }
        else if (j == 2)
        {
            return i + (b * j);
        }
        else
        {
            return i + (c * j);
        }
    }) << endl;
    return 0;
}
