#include <iostream>

using namespace std;

int main()
{
    int n;
    char x;
    cin >> n >> x;
    while (n--)
    {
        char a, b;
        cin >> a >> b;

        if (a == x)
        {
            x = b;
        }
        else if (b == x)
        {
            x = a;
        }
    }

    cout << x << endl;
    return 0;
}
