#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int js[4] = {0, 2, 6, 8};
const int js2[2] = {1, 7};

int main()
{
    int count = 0;
    long long res = 1;
    vector<string> barcode(9);
    for (int i = 0; i < 9; ++i)
    {
        cin >> barcode[i];
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int x : js)
        {
            if (barcode[x][i] == '0' || barcode[x][i + 6] == '0')
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    for (int x : js2)
    {
        if (barcode[x][0] == '0' || barcode[x][1] == '1' || barcode[x][2] == '0' ||
                barcode[x][6] == '0' || barcode[x][7] == '1' || barcode[x][8] == '0')
        {
            cout << 0 << endl;
            return 0;
        }
    }

    for (int i = 3; i < 6; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (barcode[j][i] == '2')
                ++count;
            if (barcode[j + 6][i] == '2')
                ++count;
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 3; j < 6; ++j)
        {
            if (barcode[j][i] == '2')
                ++count;
        }
    }

    res <<= count;
    cout << res << endl;
    return 0;
}
