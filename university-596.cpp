#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> fib;

    int a = 0;
    int b = 1;
    int c = 1;
    int index = 1;
    while (b < n)
    {
        c = a + b;
        fib.push_back(pair<int, int>(index, c));
        ++index;
        a = b;
        b = c;
    }

    index = fib.size() - 1;
    while (n > 0 && index >= 0)
    {
        if ((n - fib[index].second) >= 0)
        {
            n -= fib[index].second;
            cout << fib[index].first << " " ;
        }

        --index;
    }

    cout << endl;
    return 0;
}
