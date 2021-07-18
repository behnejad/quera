#include <iostream>

using namespace std;

int main()
{
    int c = 0;
    int i;
    for (auto j = 0; j < 5; ++j)
    {
        cin >> i;
        if (i >= 80)
        {
            ++c;
        }
    }

    if (c >= 3)
    {
        cout << "Mamma mia!" << endl;
    }
    else if (c == 1 || c == 2)
    {
        cout << "Mamma mia!!" << endl;
    }
    else
    {
        cout << "Mamma mia!!!" << endl;
    }

    return 0;
}
