#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    map<int, vector<pair<char, int>>> rules;
    string letter;
    int n, m, state = 1;
    size_t index = 0;
    char * ptr;
    cin >> n >> m >> letter;
    ptr = letter.data();

    int v, u;
    char c;

    while (m--)
    {
        cin >> v >> u >> c;
        if (rules.count(v) == 0)
        {
            rules[v] = vector<pair<char, int>>();
        }

        rules[v].emplace_back(c, u);
    }

    bool loop = true;
    while (loop)
    {
        if (index == letter.size())
        {
            break;
        }

        if (rules.count(state) == 0)
        {
            break;
        }

        loop = false;
        for (pair<char, int> & x : rules[state])
        {
            if (x.first == *ptr)
            {
                state = x.second;
                ++index;
                ++ptr;
                loop = true;
                break;
            }
        }
    }

    if (index == letter.size())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ptr << endl;
    }

    return 0;
}
