#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    string s;
    getline(cin, s);
    t = stoi(s);
    while (t > 0)
    {
        getline(cin, s);
        bool last = true;
        for (char & i : s)
        {
            if (isdigit(i))
            {
                continue;
            }

            if (isblank(i))
            {
                last = true;
                continue;
            }

            if (last)
            {
                i = toupper(i);
                last = false;
            }
            else
            {
                i = tolower(i);
            }
        }

        cout << s << endl;
        --t;
    }

    return 0;
}
