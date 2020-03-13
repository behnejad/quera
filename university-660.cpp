#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class person
{
public:
    vector<person *> list;
    string name;
    int give;
    int get;
    int org;
};

int main()
{
    int n;
    cin >> n;

    string temp;
    map<string, person *> m;
    vector<person *> list;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        person * tp = new person;
        tp->get = 0;
        m[temp] = tp;
        list.push_back(tp);
        tp->name = move(temp);
    }

    for (int i = 0; i < n; ++i)
    {
        int j;
        person * pt;
        cin >> temp;
        pt = m[temp];
        cin >> pt->give >> j;
        pt->org = pt->give;
        while (j--)
        {
            cin >> temp;
            pt->list.push_back(m[temp]);
        }
    }

    for_each(list.begin(), list.end(), [](person * i) {
        if (!i->list.empty())
        {
            int rem = i->give % i->list.size();
            for (int j = 0; j < i->list.size(); ++j)
            {
                i->list[j]->get += i->give / i->list.size();
            }
            i->give = rem;
        }
    });

    for_each(list.begin(), list.end(), [](person * i) {
        cout << i->name << " " << i->get + i->give - i->org << endl;
        delete i;
    });

    return 0;
}
