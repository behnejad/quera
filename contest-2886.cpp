#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int h, m;
    cin >> h >> m;
    h = h != 0 && h != 6 ? 12 - h : h;
    m = m != 0 && m != 30 ? 60 - m : m;
    cout << setfill('0') << setw(2) << h << ":" <<
            setfill('0') << setw(2) << m << endl;
    return 0;
}
