#include <iostream>
#include <string>

using namespace std;

int main()
{
    int res = 0;
    string s;
    cin >> s;
    for (auto c : s)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            ++ res;
        }
    }
    cout << (1 << res) << endl;
    return 0;
}
