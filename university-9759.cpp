#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <map>

using namespace std;

class node
{
public:
    map<int, int> neighbors;
    bool visited = false;
    bool has_cow = false;
};

vector<node> farm('z' - 'a' + 1);

long long short_path = numeric_limits<long long>::max();
char farm_path = '-';

void find(long long d, int i)
{
    if (farm[i].has_cow)
    {
        if (short_path > d)
        {
            short_path = d;
            farm_path = 'A' + i;
        }
    }

    for (pair<int, int> x : farm[i].neighbors)
    {
        if (farm[x.first].visited == false)
        {
            farm[x.first].visited = true;
            find(d + x.second, x.first);
            farm[x.first].visited = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char i, j;
        int d;
        cin >> i >> j >> d;

        if (isupper(i))
        {
            i = tolower(i);
            farm[i - 'a'].has_cow = true;
        }

        if (isupper(j))
        {
            j = tolower(j);
            farm[j - 'a'].has_cow = true;
        }

        i -= 'a';
        j -= 'a';

        if (farm[i].neighbors.count(j) == 0)
        {
            farm[i].neighbors[j] = d;
            farm[j].neighbors[i] = d;
        }
        else
        {
            if (farm[i].neighbors[j] > d)
            {
                farm[i].neighbors[j] = d;
                farm[j].neighbors[i] = d;
            }
        }
    }

    farm['z' - 'a'].has_cow = false;
    farm['z' - 'a'].visited = true;
    find(0, 'z' - 'a');

    cout << farm_path << " " << short_path << endl;
    return 0;
}
