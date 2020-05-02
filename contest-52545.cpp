#include <iostream>

using namespace std;

int main()
{
    int max = 0, t, index = 0;
    for (int i = 0; i < 12; ++i)
    {
        cin >> t;
        if (max < t)
        {
            max = t;
            index = i / 3;
        }
    }

    cout << index + 1 << endl;
    return 0;
}
