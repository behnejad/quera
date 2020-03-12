#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long double min = numeric_limits<long double>::max();
    long double max = numeric_limits<long double>::min();
    long double sum = 0;
    float temp;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        sum += temp;
        if (min > temp)
        {
            min = temp;
        }
        if (max < temp)
        {
            max = temp;
        }
    }

    cout << fixed << setprecision(3);
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Avg: " << (sum / n) << endl;

    return 0;
}
