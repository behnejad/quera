#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n == 2)
    {
        cout << 1 << endl << 1 << " " << 1 << endl;
    }
    else if (n > 2)
    {
        cout << 1 << endl;
        vector<int> last, now;
        last.push_back(1);
        last.push_back(1);

        for (int i = 0; i < n - 1; ++i)
        {
            now.push_back(1);
            for (int j = 0; j < i; ++j)
            {
                now.push_back(last[j] + last[j + 1]);
            }
            now.push_back(1);
            for (int j : now)
            {
                cout << j << " ";
            }
            cout << endl;

            last = move(now);
        }
    }
    return 0;
}
