#include <iostream>

using namespace std;

int main()
{
    int need, have;
    cin >> need >> have;
    long long price = 0;
    have += 60;
    if (need >= have)
    {
        price += (have * 1500);
        need -= have;
    }
    else
    {
        price += (need * 1500);
        need = 0;
    }

    if (need > 0)
    {
        price += (need * 3000);
    }
    cout << price << endl;
    return 0;
}
