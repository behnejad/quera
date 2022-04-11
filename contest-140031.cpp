#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i;
    cin >> i;
    string s = to_string(i);
    int j = 0;
    for (auto x : s)
    {
        j += (x - '0');
    }
    cout << j << endl;
    return 0;
}
