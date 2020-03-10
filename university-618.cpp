#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string row;

    n = n << 1;
    ++n;
    int s = -1;
    for (int i = 0; i < n; ++i)
    {
        s += ((i << 1) + 1 > n) ? -2 : +2;
        int w = (n - s + 1) /2;
        for (int j = 0 ; j < w; ++j)
        {
            row += ' ';
        }
        for (int j = 0; j < s; ++j)
        {
            row += '*';
        }
        cout << row << endl;
        row.clear();
    }

    return 0;
}
