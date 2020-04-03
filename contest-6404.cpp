#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef pair<set<int>, set<int>> rule_t;

bool check_exist(set<int> & req, set<int> & have)
{
    for (int i : req)
    {
        if (have.count(i) == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    set<int> have;
    vector<pair<bool, rule_t>> rules;
    rule_t rule;

    int n, m, k, temp, p, q;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i)
    {
        cin >> temp;
        have.insert(temp);
    }

    while (k--)
    {
        cin >> p >> q;

        for (int i = 0; i < p; ++i)
        {
            cin >> temp;
            rule.first.insert(temp);
        }

        for (int i = 0; i < q; ++i)
        {
            cin >> temp;
            rule.second.insert(temp);
        }

        rules.emplace_back(false, move(rule));
    }

    while (true)
    {
        bool not_used = true;

        for (size_t i = 0; i < rules.size(); ++i)
        {
            if (rules[i].first == false && check_exist(rules[i].second.first, have))
            {
                not_used = false;
                for (int x : rules[i].second.second)
                {
                    have.insert(x);
                }

                rules[i].first = true;
            }
        }

        if (not_used)
        {
            break;
        }
    }

    cout << have.size() << endl;
    for (int x : have)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
