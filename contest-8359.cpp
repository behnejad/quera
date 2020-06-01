#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main()
{
    istringstream cline;
    string line;

    int n, m, k;
    getline(cin, line);
    cline.str(line);
    cline >> n >> m >> k;

    vector<set<string>> valid_words(m);
    vector<vector<string>> person_word(n);
    vector<int> scores(n, 0);

    for (int i = 0; i < n; ++i)
    {
        person_word[i].resize(m);
    }

    for (int i = 0; i < m; ++i)
    {
        getline(cin, line);
        cline.clear();
        cline.str(line);

        while (!cline.eof())
        {
            cline >> line;
            valid_words[i].insert(line);
        }
    }

    while (k--)
    {
        getline(cin, line);
        cline.clear();
        cline.str(line);

        char h;
        cline >> h;

        vector<map<string, int>> columns(m);

        for (int i = 0; i < n; ++i)
        {
            getline(cin, line);
            cline.clear();
            cline.str(line);

            for (int j = 0; j < m; ++j)
            {
                cline >> person_word[i][j];

                if (columns[j].count(person_word[i][j]) == 0)
                {
                    columns[j][person_word[i][j]] = 1;
                }
                else
                {
                    columns[j][person_word[i][j]] += 1;
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (person_word[i][j] != "EMPTY" && person_word[i][j][0] == h && valid_words[j].count(person_word[i][j]))
                {
                    if (columns[j][person_word[i][j]] == 1)
                    {
                        scores[i] += 10;
                    }
                    else
                    {
                        scores[i] += 5;
                    }
                }
            }
        }
    }

    for (int x : scores)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
