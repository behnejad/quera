#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    int aa = a + (m * c);
    int bb = b + (m * d);
    if (aa > bb)
    {
        if (c > d)
        {
            cout << "Eyval baba!" << endl;
        }
        else
        {
            cout << "Naaa, eshtebahe!" << endl;
        }
    }
    else
    {
        if (c < d)
        {
            cout << "Eyval baba!" << endl;
        }
        else
        {
            cout << "Naaa, eshtebahe!" << endl;
        }
    }
    return 0;
}
