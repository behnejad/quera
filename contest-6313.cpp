#include <iostream>

using namespace std;

int main()
{
    long long t;
    while (true)
    {
        cin >> t;
        if (t == 0)
        {
            break;
        }

        if (t <= 1000000)
        {
            cout << t << endl;
        }
        else if (t <= 5000000)
        {
            cout << t - (t / 10) << endl;
        }
        else
        {
            cout << t - (t / 5) << endl;
        }
    }
    return 0;
}
