#include <iostream>

using namespace std;

int main()
{
    int j, f, m, n, temp, turn = 0;
    cin >> j >> f >> m >> n;

    int jj = 0, ff = 0, mm = 0, nn = 0;

    while (j != 0 && f != 0 && m != 0 && n != 0)
    {
        switch(turn)
        {
        case 0:
            ++jj;
            --j;
            turn = 1;
            break;
        case 1:
            ++ff;
            --f;
            turn = 2;
            break;
        case 2:
            ++mm;
            --m;
            turn = 3;
            break;
        case 3:
            ++nn;
            --n;
            turn = 0;
            break;
        }

        temp = j;
        j = f;
        f = m;
        m = n;
        n = temp;
    }


    cout << jj << " " << ff << " " << mm << " " << nn << endl;
    return 0;
}
