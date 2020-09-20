#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

void print(set<int> & set)
{
    if (set.size() == 0)
    {
        cout << "{ }" << endl;
    }
    else if (set.size() == 1)
    {
        cout << "{ " << *set.begin() << " }" << endl;
    }
    else
    {
        cout << "{ ";
        std::set<int>::iterator it = set.begin();
        cout << *it;
        ++it;
        std::set<int>::iterator itl = set.end();
        while (it != itl)
        {
            cout << " " << *it;
            ++it;
        }
        cout << " }" << endl;
    }
}

void power_set(set<int> & set, int index, int depth)
{
    if (index == depth)
        return;

    for (int i = index + 1; i < depth; ++i)
    {
        set.insert(i);
        power_set(set, i, depth);
        print(set);
        set.erase(i);
    }
}

int main()
{
    int i;
    cin >> i;
    set<int> myset;
    power_set(myset, 0, i + 1);
    print(myset);
    return 0;
}
