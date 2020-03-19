#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main1()
{
    int n, l, t = 0, d = 0;
    cin >> n >> l;
    vector<tuple<int, int, int>> m;

    while (n--)
    {
        int di, ri, gi;
        cin >> di >> ri >> gi;
        m.emplace_back(di, ri, gi);
    }

    for (tuple<int, int, int> & x : m)
    {

    }

    cout << t << endl;
    return 0;
}
