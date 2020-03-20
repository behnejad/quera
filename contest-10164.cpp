#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int count = 0;
    vector<string> map;
    for (int i = 0; i < 7; ++i)
    {
        string s;
        cin >> s;
        map.push_back(move(s));
    }

    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (map[i][j] == 'o')
            {
                if (j <= 1)
                {
                    if (map[i][j + 1] == 'o' && map[i][j + 2] == '.')
                    {
                        ++count;
                    }

                    if (i <= 4 && map[i + 1][j] == 'o' && map[i + 2][j] == '.')
                    {
                        ++count;
                    }

                    if (i >= 2 && map[i - 1][j] == 'o' && map[i - 2][j] == '.')
                    {
                        ++count;
                    }
                }
                else if (j >= 5)
                {
                    if (map[i][j - 1] == 'o' && map[i][j - 2] == '.')
                    {
                        ++count;
                    }

                    if (i <= 4 && map[i + 1][j] == 'o' && map[i + 2][j] == '.')
                    {
                        ++count;
                    }

                    if (i >= 2 && map[i - 1][j] == 'o' && map[i - 2][j] == '.')
                    {
                        ++count;
                    }
                }
                else
                {
                    if (map[i][j + 1] == 'o' && map[i][j + 2] == '.')
                    {
                        ++count;
                    }

                    if (map[i][j - 1] == 'o' && map[i][j - 2] == '.')
                    {
                        ++count;
                    }

                    if (i <= 4 && map[i + 1][j] == 'o' && map[i + 2][j] == '.')
                    {
                        ++count;
                    }

                    if (i >= 2 && map[i - 1][j] == 'o' && map[i - 2][j] == '.')
                    {
                        ++count;
                    }
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
