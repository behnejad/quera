#include <iostream>
#include <string>
#include <vector>

using namespace std;

string r;
vector<int> err;
int minx;

bool check()
{
    int open = 0;
    for (char x : r)
    {
        if (x == '(')
        {
            ++open;
        }
        else
        {
            if (open == 0)
            {
                return false;
            }
            else
            {
                --open;
            }
        }
    }

    return open == 0;
}

void job(int count)
{
    if (check())
    {
        if (minx > count)
        {
            minx = count;
        }
    }
    else
    {
        for (int & x : err)
        {
            if (x != -1)
            {
                int t = x;
                x = -1;
                r[x] = r[x] == ')' ? '(' : ')';
                job(count + 1);
                x = t;
                r[x] = r[x] == ')' ? '(' : ')';
            }
        }
    }
}

int main()
{
    int open = 0;
    cin >> r;
    minx = r.size();

    for (int i = 0; i < r.size(); ++i)
    {
        if (r[i] == '(')
        {
            ++open;
        }
        else
        {
            if (open == 0)
            {
                err.push_back(i);
                ++open;
            }
            else
            {
                --open;
            }
        }
    }

    job(0);
    cout << minx << endl;

    return 0;
}
