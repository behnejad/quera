#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string s, t;
    int n, count = 0;
    cin >> s >> n;

    while(n--)
    {
        cin >> t;
        if (t.size() >= s.size())
        {
            int i = 0, j = 0;
            while (i < t.size() && j < s.size())
            {
                if (t[i] == s[j])
                    ++j;
                ++i;
            }

            if (j == s.size())
            {
                ++count;
            }
            /*
            int delta = t.size() - s.size();
            for (int i = 0; i < delta; ++i)
            {
                if (memcmp(t.data() + i, s.data(), s.size()) == 0)
                {
                    ++count;
                    break;
                }
            }
            */
        }
    }

    cout << count << endl;

    return 0;
}
