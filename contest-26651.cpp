#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    long sum = 0;

    cin >> n;
    vector<int> row(n);

    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        row[i] = t;
    }

    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        sum += row[i] * t;
    }

    cout << sum << endl;

    return 0;
}
