#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int row = n / 2;
    int col = (n % 2) + row;
    cout << (row + 1) * (col + 1) << endl;
    return 0;
}
