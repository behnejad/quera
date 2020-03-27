#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    while(n--)
    {
        string a, b;
        getline(cin, a);
        while (a.size() == 0)
        {
            getline(cin, a);
        }
        getline(cin, b);
        while (b.size() == 0)
        {
            getline(cin, b);
        }
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] == ' ')
            {
                ++i;
            }
            else if (b[j] == ' ')
            {
                ++j;
            }
            else if (a[i] != b[j])
            {
                ++count;
                break;
            }
            else
            {
                ++i;
                ++j;
            }
        }
    }
    cout << count << endl;
    return 0;
}
