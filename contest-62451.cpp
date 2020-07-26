#include <iostream>

using namespace std;

int main()
{
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;

    if (v1 - v2 == 0)
    {
        cout << "WAIT WAIT" << endl;
    }
    else
    {
        int v = (v1 - v2);
        int x = (x2 - x1);
        int t = x / v;
        if (t < 0)
        {
            cout << "BORO BORO" << endl;
        }
        else
        {
            cout << "SEE YOU" << endl;
        }
    }
    return 0;
}
