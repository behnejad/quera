#include <iostream>
#include <set>

using namespace std;

typedef long double myL;

myL maxi = 0;
set<myL> a, b;

bool check(myL i)
{
    if (i > maxi)
    {
        return false;
    }

    myL t = i * 2;
    if (a.count(t))
    {
        a.erase(t);
        return true;
    }

    if (a.count(t + 1))
    {
        a.erase(t + 1);
        return true;
    }

    return check(t) || check(t + 1);
}

int main()
{
    int n;
    myL temp;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        if (maxi < temp)
        {
            maxi = temp;
        }
        a.insert(temp);
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        b.insert(temp);
    }

    bool k = true;
    for (long long x : b)
    {
        if (check(x) == false)
        {
            k = false;
            break;
        }
    }

    cout << (k ? "YES" : "NO") << endl;
    return 0;
}
