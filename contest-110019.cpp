#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

#define DEP 1
#define WIT 2

class tran
{
public:
    bool ok;
    int time;
    int amount;
    int type;
};

int main()
{
    int n, h, m;
    cin >> n;
    vector<tran> arr(n);
    string temp;
    char c;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        if (temp == "DEP")
        {
            arr[i].type = DEP;
        }
        else
        {
            arr[i].type = WIT;
        }
        cin >> arr[i].amount;
        cin >> h >> c >> m;
        arr[i].time = h * 100 + m;
        arr[i].ok = false;
        if (arr[i].type == WIT)
        {
            cin >> temp;
            if (temp == "OK")
            {
                arr[i].ok = true;
            }
        }
    }

    sort(arr.begin(), arr.end(), [](auto & a, auto & b) { return a.time < b.time; });

    bool error = false;
    int shift = 0;
    int base = 0;

    if (arr[0].type == DEP)
    {
        base += arr[0].amount;
    }
    else if (arr[0].ok)
    {
        shift += arr[0].amount;
    }

    arr.erase(arr.begin());

    for (auto & x : arr)
    {
        if (x.type == DEP)
        {
            base += x.amount;
        }
        else
        {
            if (x.ok)
            {
                if (x.amount > base)
                {
                    shift += x.amount - base;
                    base = 0;
                }
                else
                {
                    base -= x.amount;
                }
            }
            else
            {
                if (x.amount <= base)
                {
                    error = true;
                    break;
                }
            }
        }
    }

    if (error)
    {
        cout << "DOROGHE" << endl;
    }
    else
    {
        cout << shift << endl;
    }

    return 0;
}
