#include <iostream>

using namespace std;

int main()
{
    int p, d, pp;
    cin >> p >> d;
    pp = p >> 1;

    int i = 1;
    while (true)
    {
        int t = i * d;
        t = t % p;
        if (t >= 0 && t <= pp)
        {
            break;
        }
        ++i;
    }

    cout << i * d << endl;

    return 0;
}
