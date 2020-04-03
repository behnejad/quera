#include <iostream>
#include <set>

using namespace std;

long long maxi = 0;
set<long long> a, b;

bool check(long long i)
{
    if (i > maxi)
    {
        return false;
    }

    if (a.count(i << 1))
    {
        return true;
    }

    if (a.count((i << 1) + 1))
    {
        return true;
    }

    return check(i << 1) || check((i << 1) + 1);
}

int main()
{
    int n;
    long long temp;
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
