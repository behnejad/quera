#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 1)
    {
        cout << n << endl;
        return 0;
    }

    vector<int> array(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }

    sort(array.begin(), array.end());
    int min = n, local_min, index = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        if (array[i] + 1 != array[i + 1])
        {
            local_min = i - index + 1;
            index = i;
            if (local_min < min)
            {
                min = local_min;
            }
        }
    }

    if (array[n - 2] + 1 != array[n - 1])
    {
        local_min = 1;
        if (local_min < min)
        {
            min = local_min;
        }
    }

    cout << min << endl;
    return 0;
}
