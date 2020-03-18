#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m, count = 0;
    cin >> n >> m;
    string i;
    while (n--)
    {
        cin >> i;
        for (char j : i)
        {
            if (j == '*')
            {
                ++count;
            }
        }
    }
    cout << count << endl;
    return 0;
}
