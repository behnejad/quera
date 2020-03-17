#include <iostream>
#include <string>

using namespace std;

int main()
{
    string i;
    cin >> i;
    int r = 0, y = 0;
    for (char t : i)
    {
        if (t == 'R')
        {
            ++r;
        }
        if (t == 'Y')
        {
            ++y;
        }
    }

    if ((r + y == i.size()) || r >= 3 || (r >= 2 && y >= 2))
    {
        cout << "nakhor lite" << endl;
    }
    else
    {
        cout << "rahat baash" << endl;
    }
    return 0;
}
