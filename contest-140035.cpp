#include <iostream>
using namespace std;

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main()
{
    int i;
    cin >> i;
    for (auto x : prime)
    {
        if (i == x && (i % 2 == 1))
        {
            cout << "zoj" << endl;
            return 0;
        }
    }
    cout << "fard" << endl;
    return 0;
}
