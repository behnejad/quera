#include <iostream>

using namespace std;

bool f(int x)
{
    int k;

    if (x==0)
    {
        return true;
    }

    for (int i = 1; i <= 54; ++i)
    {
        int sum=0;
        k = x - i;
        for (k; k > 0; k /= 10)
        {
            sum += k % 10;
        }

        if (i==sum)
        {
            return true;
        }
    }

    return false;
}

int main ()
{
    int n, x;
    cin >> n;

    while (n--)
    {
        cin >> x;
        cout << (f(x) ? "Yes" : "No") << endl;
    }

    return 0;
}
