#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int w, b, s;

    cin >> b >> w;
    s = w + b;

    vector<int> arr;
    for (int i = 3; i < s; ++i)
    {
        if (s % i == 0)
        {
            arr.push_back(i);
        }
    }

    for (auto x : arr)
    {
        int y = s / x;
        if ((x - 2) * (y - 2) == w)
        {
            cout << (x > y ? x : y) << " " << (x > y ? y : x) << endl;
            break;
        }
    }

    return 0;
}
