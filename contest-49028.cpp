#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    int state = -1;
    while (n--)
    {
        int t;
        cin >> t;
        if (state == -1)
        {
            state = t;
        }
        else
        {
            if (state != t)
            {
                ++count;
                state = t;
            }
        }
    }
    cout << count << endl;
    return 0;
}
