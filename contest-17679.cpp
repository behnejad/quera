#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    int arr2[n + 1], arr[n + 1];
    vector<long long> arrayList;

    memset(arr, 0, sizeof (arr));
    memset(arr2, 0, sizeof (arr2));

    arrayList.push_back(0);

    for (int i = 0; i < q; ++i)
    {
        int command;
        cin >> command;
        if (command == 1)
        {
            int number;
            cin >> number;
            arrayList.push_back(arrayList[arrayList.size() - 1] + number);
        }
        else
        {
            int i2, j;
            cin >> i2 >> j;
            arr2[i2] += j;
            cout << arrayList[arr2[i2]] - arrayList[arr[i2]] << endl;
            arr[i2] += j;
        }
    }

    return 0;
}
