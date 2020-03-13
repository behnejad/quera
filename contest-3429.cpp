#include <iostream>

using namespace std;

int main()
{
    int i;
    cin >> i;
    if (i > 100)
    {
        cout << "Steam" << endl;
    }
    else if (i < 0)
    {
        cout << "Ice" << endl;
    }
    else
    {
        cout << "Water" << endl;
    }
    return 0;
}
