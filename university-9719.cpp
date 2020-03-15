#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void change_base(vector<int> & v, int i, int b)
{
    int rem;
    if (i < b)
    {
        v.push_back(i);
        return;
    }

    while (i >= b)
    {
        rem = i % b;
        v.push_back(rem);
        i /= b;
    }
    v.push_back(i);
}

void check(int i, int b)
{
    int ii = i * i;

    vector<int> inb, iinb;
    change_base(iinb, ii, b);
    int st = 0, en = iinb.size() - 1;
    bool reverse = true;
    while (st <= en && reverse)
    {
        if (iinb[st] != iinb[en])
        {
            reverse = false;
        }
        ++st;
        --en;
    }

    if (reverse)
    {
        change_base(inb, i, b);
        std::reverse(inb.begin(), inb.end());
        for (int i : inb)
        {
            cout << (char)((i >= 10) ? ('A' + i - 10) : ('0' + i));
        }
        cout << " ";
        std::reverse(iinb.begin(), iinb.end());
        for (int i : iinb)
        {
            cout << (char)((i >= 10) ? ('A' + i - 10) : ('0' + i));
        }
        cout << endl;
    }
}

int main()
{
    int b;
    cin >> b;

    int i = 1;
    while (i <= 300)
    {
        check(i, b);
        ++i;
    }

    return 0;
}
