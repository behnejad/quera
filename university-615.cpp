#include <iostream>
#include <string>

using namespace std;

int main()
{
    string i;
    cin >> i;

    cout << "saal:" << i.substr(0, 2) << endl << "maah:" << i.substr(2, 4) << endl;

    return 0;
}
