#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, t;
    long sum = 0;
    cin >> n >> k;
    while (n--)
    {
        cin >> t;
        sum += t;
    }
    cout << (sum >= k ? "YES" : "NO") << endl;
    return 0;
}
