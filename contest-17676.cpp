#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> map;

    while (n--)
    {
        string temp;
        cin >> temp;
        map.push_back(move(temp));
    }

    m = 0;

    for (int i = 0; i < map.size(); ++i)
    {
        string & temp = map[i];
        for (int j = 0; j < temp.size(); ++j)
        {
            if (temp[j] == '|')
            {
                ++m;
                for (int k = j; k < temp.size(); ++k)
                {
                    if (temp[k] == '|')
                    {
                        temp[k] = 0;
                        ++j;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if (temp[j] == '-')
            {
                ++m;
                for (int k = j; k < map.size(); ++k)
                {
                    if (map[k][j] == '-')
                    {
                        map[k][j] = 0;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    cout << m << endl;

    return 0;
}
