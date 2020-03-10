#include <iostream>
#include <vector>

using namespace std;

vector<long> pri;

void prime(long i)
{
    if (i == 1)
        return;

    if (i == 2)
    {
        pri.push_back(i);
        return;
    }

    long t = i - 1;
    while (t > 1)
    {
        if ((i % t) == 0)
        {
            return;
        }
        --t;
    }
    pri.push_back(i);
}

void print(vector<long> & set)
{
    if (set.size() == 0)
    {

    }
    else if (set.size() == 1)
    {
        cout << *set.begin() << endl;
    }
    else
    {
        vector<long>::iterator it = set.begin();
        cout << *it;
        ++it;
        vector<long>::iterator itl = set.end();
        while (it != itl)
        {
            cout << "," << *it;
            ++it;
        }
        cout << endl;
    }
}

int main()
{
    long i, j;
    cin >> i >> j;
    ++i;
    while (i < j)
    {
        prime(i);
        ++i;
    }

    print(pri);

    return 0;
}
