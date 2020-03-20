#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    bool caps = false;
    cin >> n;
    string t = "", i;
    while (n--)
    {
        cin >> i;
        if (i == "CAPS")
        {
            caps = !caps;
        }
        else if (caps)
        {
            t += toupper(i[0]);
        }
        else
        {
            t += i[0];
        }
    }
    cout << t << endl;
    return 0;
}
