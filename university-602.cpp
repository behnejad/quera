#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isA(double x, double y)
{
    return abs(x - (int)x - y) <= 2.0;
}

bool isB(double x, double y)
{
    return abs((x * x) + x - y) <= 2.0;
}

bool isC(double x, double y)
{
    x = (x * x * x);
    return abs(abs(1 - x) + x - y) <= 2.0;
}

int main()
{
    vector<pair<double, double>> array;
    int n;
    cin >> n;
    double x, y;

    while (n--)
    {
        cin >> x >> y;
        array.push_back(pair<double, double>(x, y));
    }

    int count = 0;
    bool all = true;
    for (int i = 0; i < array.size() && all; ++i)
    {
        all = isA(array[i].first, array[i].second);
//        if (!all)
//        {
//            cout << i << " A" << endl;
//        }
    }

    count += all ? 1 : 0;


    all = true;
    for (int i = 0; i < array.size() && all; ++i)
    {
        all = isB(array[i].first, array[i].second);
//        if (!all)
//        {
//            cout << i << " B" << endl;
//        }
    }

    count += all ? 1 : 0;


    all = true;
    for (int i = 0; i < array.size() && all; ++i)
    {
        all = isC(array[i].first, array[i].second);
//        if (!all)
//        {
//            cout << i << " C" << endl;
//        }
    }

    count += all ? 1 : 0;

    if (count == 0)
    {
        cout << "No ones" << endl;
    }
    else
    {
        cout << count << endl;
    }

    return 0;
}
