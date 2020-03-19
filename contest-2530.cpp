#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int count = 1;
    for (char x : s)
    {
        if (x == 'F' || x == 'L' || x == 'D' || x == 'T')
        {
            count <<= 1;
        }
    }
    cout << count << endl;
    return 0;
}
