#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, m = 0;
    cin >> n >> k;
    vector<int> a;
    while (n--)
    {
        int i;
        cin >> i;
        a.push_back(i);
    }

    int t = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (t + a[i] > k)
        {
            ++m;
            t = a[i];
        }
        else
        {
            t += a[i];
        }
    }

    cout << m + 1 << endl;
    return 0;
}
