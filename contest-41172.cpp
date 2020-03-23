#include <iostream>

using namespace std;

int main()
{
    long long w, n, x, y, sum = 0;
    cin >> w >> n;
    while (n--)
    {
        cin >> x >> y;
        sum += (x * y);
    }
    cout << sum / w << endl;
    return 0;
}
