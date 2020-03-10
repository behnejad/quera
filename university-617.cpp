#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    cin >> a;

    int i = 0;
    int j = a.size() - 1;
    while (i <= j)
    {
        if (a.at(i) != a.at(j))
        {
            cout << "NO" << endl;
            return 0;
        }
        ++i;
        --j;
    }

    cout << "YES" << endl;
    return 0;
}
