#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    istringstream cline;
    ostringstream clineout;
    string temp;

    getline(cin, temp);
    cline.clear();
    cline.str(temp);

    int n;
    cline >> n;

    set<string> words;

    getline(cin, temp);
    cline.clear();
    cline.str(temp);

    for (int i = 0; i < n; ++i)
    {
        cline >> temp;
        words.insert(temp);
    }

    getline(cin, temp);
    cline.clear();
    cline.str(temp);

    while (!cline.eof())
    {
        cline >> temp;

        int count = 0;

        for (const string & x : words)
        {
            bool found = false;

            if (x.length() == temp.length())
            {
                found = true;

                for (size_t i = 0; i < temp.length(); ++i)
                {
                    if (isalpha(temp[i]) && (temp[i] != x[i]))
                    {
                        found = false;
                        break;
                    }
                }
            }

            if (found)
            {
                ++count;

                if (count == 1)
                {
                    clineout << x << " ";
                }

                if (count == 2)
                {
                    cout << "multiple" << endl;
                    return 0;
                }
            }
        }

        if (count == 0)
        {
            cout << "not recoverable" << endl;
            return 0;
        }
    }

    cout << clineout.str() << endl;

    return 0;
}
