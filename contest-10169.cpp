#include <iostream>
#include <string>

using namespace std;

int main()
{
    int last_index = 0, h;
    string path;
    cin >> h >> path;
    h = (1 << (h + 1)) - 1;
    for (char x : path)
    {
        last_index <<= 1;
        if (x == 'L')
        {
            last_index += 1;
        }
        else if (x == 'R')
        {
            last_index += 2;
        }
    }
    cout << h - last_index << endl;
    return 0;
}
