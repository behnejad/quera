#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isA(double x, double y)
{
    return abs(x - floor(x) - y) <= 0.2;
}

bool isB(double x, double y)
{
    return abs((x * x) + x - y) <= 0.2;
}

bool isC(double x, double y)
{
    x = (x * x * x);
    return abs(abs(1 - x) + x - y) <= 0.2;
}

int main()
{
    vector<pair<double, double>> array;
    int n;
    cin >> n;
    double x, y;
    bool f = true;

    while (n--)
    {
        cin >> x >> y;
        array.push_back(pair<double, double>(x, y));
    }

    bool all = true;
    for (int i = 0; i < array.size() && all; ++i)
    {
        all = isA(array[i].first, array[i].second);
    }

    if (all)
    {
        f = false;
        cout << 1 << endl;
    }

    all = true;
    for (int i = 0; i < array.size() && all; ++i)
    {
        all = isB(array[i].first, array[i].second);
    }

    if (all)
    {
        f = false;
        cout << 2 << endl;
    }

    all = true;
    for (int i = 0; i < array.size() && all; ++i)
    {
        all = isC(array[i].first, array[i].second);
    }

    if (all)
    {
        f = false;
        cout << 3 << endl;
    }

    if (f)
    {
        cout << "No ones" << endl;
    }

    return 0;
}
