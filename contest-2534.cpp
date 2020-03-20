#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    long long sum = 0;
    cin >> n;

    vector<int> c(n, 0);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        c[i] = t;
        sum += t;
    }

    int mean = sum / n;
    int count = 0;
    for (int x : c)
    {
        if (x < mean)
        {
            count += (mean - x);
        }
    }

    cout << count << endl;
    return 0;
}
