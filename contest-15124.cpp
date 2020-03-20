#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b, x, count = 0;
    cin >> a >> b >> x;
    vector<int> aa, bb;

    for (int i = 1; i <= a; ++i)
    {
        if (a % i == 0)
        {
            aa.push_back(i);
        }
    }

    for (int i = 1; i <= b; ++i)
    {
        if (b % i == 0)
        {
            bb.push_back(i);
        }
    }

    for (int i : aa)
    {
        for (int j : bb)
        {
            if (i + j <= x)
            {
                ++count;
            }
        }
    }


    cout << count << endl;
    return 0;
}
