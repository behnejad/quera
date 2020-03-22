#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

set<int> cc;
set<string> halat;
int ma, mb, mc;

void job(int a, int b, int c)
{
    ostringstream ss;
    ss << a << "-" << b << "-" << c;
    string h = ss.str();

    if (halat.count(h) == 0)
    {
        halat.insert(move(h));
        if (a == 0)
        {
             cc.insert(c);
        }

        int dta = ma - a;
        int dtb = mb - b;
        int dtc = mc - c;

        if (dta > 0)
        {
            // a < b
            if (b >= dta)
            {
                job(ma, b - dta, c);
            }
            else if (b > 0)
            {
                job (a + b, 0, c);
            }

            // a < c
            if (c >= dta)
            {
                job(ma, b, c - dta);
            }
            else if (c > 0)
            {
                job(a + c, b, 0);
            }
        }

        if (dtc > 0)
        {
            // b > c
            if (b >= dtc)
            {
                job(a, b - dtc, mc);
            }
            else if (b > 0)
            {
                job(a, 0, c + b);
            }

            // a > c
            if (a >= dtc)
            {
                job(a - dtc, b, mc);
            }
            else if (a > 0)
            {
                job (0, b, c + a);
            }
        }

        if (dtb > 0)
        {
            // a > b
            if (a >= dtb)
            {
                job(a - dtb, mb, c);
            }
            else if (a > 0)
            {
                job(0, b + a, c);
            }

            // b < c
            if(c >= dtb)
            {
                job(a, mb, c - dtb);
            }
            else if (c > 0)
            {
                job(a, b + c, 0);
            }
        }
    }
}

int main()
{
    cin >> ma >> mb >> mc;
    job(0, 0, mc);
    for (int x : cc)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
