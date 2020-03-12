#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, t;
    string row;
    vector<int> res(20*100 + 1);
    cin >> n;
    while (n--)
    {
        cin >> row;
        for (int j = row.size() - 1,i = res.size() - 1; j >= 0; --j, --i)
        {
            t = res[i] + row[j] - '0';
            if (t > 9)
            {
                res[i - 1] += (t / 10);
                res[i] = t % 10;
            }
            else
            {
                res[i] = t;
            }
        }
    }

    bool start = true;
    for(int i : res)
    {
        if (start)
        {
            if (i == 0)
            {
                continue;
            }
            else
            {
                cout << i;
                start = false;
            }
        }
        else
        {
            cout << i;
        }
    }

    if (start)
    {
        cout << 0;
    }

    cout << endl;

    return 0;
}
