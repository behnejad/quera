#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

class yal
{
public:
    yal(int _id, int _dest) : id(_id), dest(_dest), visited(false) {}
    int id;
    int dest;
    bool visited;
};

class node
{
public:
    node() : visited(false) {}
    vector<yal> yals;
    bool visited;
    ~node() = default;
};

vector<node> nodes;
deque<int> path_yals;
set<int> uniq_yals;

int n, m, s, t, mi, ma, d;
int id, sn, dn;

void dfs(int cnode, int dnode, int depth)
{
    if (depth > ma)
    {
        return;
    }
    else if (cnode == dnode)
    {
//        cout << "reach destiny" << endl;
        if (depth >= mi)
        {
//            cout << "reach destiny correct depth" << endl;
            for (int x : path_yals)
            {
                uniq_yals.insert(x);
            }

            return;
        }
    }
    else
    {
        node & k = nodes[cnode];
        k.visited = true;
        for (yal & y : k.yals)
        {
//            cout << "checking node " << y.dest + 1 << endl;
            if (y.visited == false && nodes[y.dest].visited == false)
            {
//                cout << "visiting node " << y.dest + 1 << endl;
                y.visited = true;
                path_yals.push_back(y.id);
                dfs(y.dest, dnode, depth + 1);
                path_yals.pop_back();
                y.visited = false;
//                cout << "end visiting node " << y.dest + 1 << endl;
            }
        }
        k.visited = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s >> t >> mi >> ma >> d;
    --s;
    --t;
    nodes.resize(n);

    for (int i = 0; i < m ;++i)
    {
        cin >> id >> sn >> dn;
        --sn;
        --dn;

        nodes[sn].yals.emplace_back(id, dn);

        if (d == 0)
        {
            nodes[dn].yals.emplace_back(id, sn);
        }
    }

    dfs(s, t, 0);

    cout << uniq_yals.size() << endl;
    if (uniq_yals.size())
    {
        for (int x : uniq_yals)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}
