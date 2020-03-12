#include <iostream>

using namespace std;

int main()
{
    int a, b, x = 0;
    cin >> a >> b;

    while (a > b)
    {
       x *= 10;
       x += a % b;
       a /= b;
    }

    x *= 10;
    x += a;

    int sum1 = 0, sum2 = 0;

    bool one = true;
    while (x > 0)
    {
        if (one)
        {
            sum1 += x % 10;
        }
        else
        {
            sum2 += x % 10;
        }

        one = !one;
        x /= 10;
    }

    cout << (sum1 == sum2 ? "Yes" : "No") << endl;

    return 0;
}
