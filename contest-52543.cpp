#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }

    sort(array.begin(), array.end());

    bool first = false;
    int i = 0, j = array.size() - 1;

    while (n--)
    {
        cout << (first ? array[i++] : array[j--]) << " ";
        first = !first;
    }
    cout << endl;

    return 0;
}
