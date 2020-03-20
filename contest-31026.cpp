#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    string a, b;
    cin >> t >> a >> t >> b;

    int max = 0;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            ++i;
            ++j;
        }
        else
        {
            break;
        }
    }

    cout << a.size() - i + b.size() - j << endl;

    return 0;
}
