#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double m, n, bmi;
    cin >> n >> m;
    bmi = n / (m * m);
    cout << fixed << setprecision(2) << bmi << endl;
    if (bmi >= 30)
    {
        cout << "Obese" << endl;
    }
    else if (bmi >= 25)
    {
        cout << "Overweight" << endl;
    }
    else if (bmi >= 18.5)
    {
        cout << "Normal" << endl;
    }
    else
    {
        cout << "Underweight" << endl;
    }
    return 0;
}
