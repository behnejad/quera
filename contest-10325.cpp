#include <iostream>

using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    cout << (c <= 10 ? "Right" : "Left") << " "
         << 10 - r + 1 << " " << (c > 10 ? 20 - c + 1: c) << endl;
    return 0;
}
