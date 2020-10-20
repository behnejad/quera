#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int s_count['z' - 'a' + 1];
int p_count['z' - 'a' + 1];

int main()
{
    int count = 0;
    memset(p_count, 0, sizeof(p_count));
    memset(s_count, 0, sizeof(s_count));
    string s, p;
    string temp;

    cin >> s >> p;

    temp.resize(p.length(), 0);
    for (char x : p)
    {
        ++p_count[x - 'a'];
    }

    int last = s.length() - p.length() + 1;

    for (int i = 0; i < last; ++i)
    {
        memcpy(temp.data(), s.data() + i, p.length());
        memset(s_count, 0, sizeof(s_count));

        for (char x : temp)
        {
            if (x != '?')
            {
                ++s_count[x - 'a'];
            }
        }

        bool ok = true;
        for (int i = 0; ok && i < ('z' - 'a' + 1); ++i)
        {
            if (s_count[i] > p_count[i])
            {
                ok = false;
            }
        }

        if (ok)
        {
            ++count;
        }
    }

    cout << count << endl;
    return 0;
}
