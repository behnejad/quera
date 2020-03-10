#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class node {
public:
    vector<node *> neighbors;
    char type = 0;
    int value = -1;
};

void solve()
{
    int e, v;
    cin >> e >> v;
    vector<node> edges(e);

    for (int i = 0; i < e; ++i)
    {
        char t;
        cin >> t;
        edges.at(i).type = t;
    }

    for (int i = 0; i < v; ++i)
    {
        int m, n;
        cin >> n >> m;
        edges.at(n).neighbors.push_back(&edges.at(m));
        edges.at(m).neighbors.push_back(&edges.at(n));
    }

    for_each(edges.begin(), edges.end(), [](auto & n) {if (n.type == 'C') {n.value = 1;}});



    for_each(edges.begin(), edges.end(), [](auto & n) {cout << n.value;});
    cout << endl;

}


int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
    return 0;
}
