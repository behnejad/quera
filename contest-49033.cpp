#include <iostream>
#include <vector>
#include <list>
#include <cstring>
#include <algorithm>

using namespace std;

void addEdge(vector<pair<int, int>>& edges,
             list<int>* tree, int x, int y)
{
    edges.push_back({x, y});
    tree[x].push_back(y);
    tree[y].push_back(x);
}

// Function to run DFS and calculate the
// height of the subtree below it
void dfs(vector<pair<int, int>>& edges, list<int>* tree,
         int node, int parent, int dp[])
{
    // Initially initialize with 1
    dp[node] = 1;

    // Traverse for all nodes connected to node
    for (auto it : tree[node]) {
        // If node is not parent
        // then recall dfs
        if (it != parent) {
            dfs(edges, tree, it, node, dp);

            // Add the size of the
            // subtree beneath it
            dp[node] += dp[it];
        }
    }
}

// Function to assign weights to edges
// to maximize the final sum
int maximizeSum(vector<pair<int, int> >& edges,
                list<int>* tree, int n)
{

    // Initialize it which stores the
    // height of the subtree beneath it
    int dp[n + 1];
    memset(dp, 0, sizeof(int) * (n + 1));

    // Call the DFS function to
    dfs(edges, tree, 1, 0, dp);

    // Stores the number of times an
    // edge is part of a path
    vector<int> ans;

    // Iterate for all edges and find the
    // number of nodes on the left and on the right
    for (auto it : edges) {

        // Node 1
        int x = it.first;

        // Node 2
        int y = it.second;

        // If the number of nodes below is less
        // then the other will be n - dp[node]
        if (dp[x] < dp[y]) {
            int fi = dp[x];
            int sec = n - dp[x];
            ans.push_back(fi * sec);
        }

        // Second condition
        else {
            int fi = dp[y];
            int sec = n - dp[y];
            ans.push_back(fi * sec);
        }
    }

    // Sort the number of times
    // an edges occurs in the path
//    sort(ans.begin(), ans.end());
    int res = 0;

    // Find the summation of all those
    // paths and return
    for (int i = 0; i < n - 1; i++) {
        res += ans[i];
    }

    return res;
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<pair<int, int> > edges;
    list<int>* tree = new list<int>[n + 1];

    int a, b, c;

    while (--n)
    {
        cin >> a >> b;
        addEdge(edges, tree, a, b);
    }

    while (q--)
    {
        cin >> c;
        if (c == 1)
        {
            cin >> a;
        }
        else
        {
            cin >> a >> b;
        }

        cout << maximizeSum(edges, tree, n) << endl;
    }

    delete[] tree;
    return 0;
}
