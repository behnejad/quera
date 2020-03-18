#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string a = "+++-+--+----+-------+------------+--------------------+---------------------------------+-----------";
    a.resize(n);
    cout << a << endl;

    /*
    set<int> fibs;

    int a = 0;
    int b = 1;
    int c = a + b;

    while(c <= n)
    {
        cout << c << endl;
        fibs.insert(c);
        a = b;
        b = c;
        c = a + b;
    }

    for (int i = 0; i < n; ++i)
    {
        if (fibs.find(i + 1) != fibs.end())
        {
            cout << "+";
        }
        else
        {
            cout << "-";
        }
    }
    cout << endl;
    */
    return 0;
}
