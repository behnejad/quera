#include <iostream>
#include <set>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    set<int> m;
    m.insert(c);

    if (b >= c)
    {
        m.insert(0);
    }
    else
    {
        m.insert(c - b);
    }

    if (a < b && b < c)
    {
        m.insert(c - a);
    }

    for (int x : m)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
