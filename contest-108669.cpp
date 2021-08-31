#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int split = -1;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i - 1] > arr[i])
        {
            split = i - 1;
            break;
        }
    }

    if (split == -1)
    {
        cout << ((arr[n - 1] <= (90 + b)) ? "YES" : "NO") << endl;
    }
    else
    {
        if (arr[split] > (45 + a))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << ((arr[n - 1] <= (90 + b)) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
