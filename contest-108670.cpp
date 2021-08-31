#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool check_upper(string & s, string & d)
{
    string a = s, b = d;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    return a == b;
}

bool check_change(string & s, string & d)
{
    int c = 0;
    for (auto i = 0; i < s.length(); ++i)
    {
        if (s[i] != d[i])
        {
            ++c;
        }
    }
    return c == 1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> src(n);
    vector<string> dst(k);
    for (auto i = 0; i < n; ++i)
    {
        cin >> src[i];
    }
    for (auto i = 0; i < k; ++i)
    {
        cin >> dst[i];
    }
    for (string & d : dst)
    {
        int sim = 0;
        for (string & s : src)
        {
            if (s.length() == d.length())
            {
                if (check_upper(s, d))
                {
                    ++sim;
                }
                else if (check_change(s, d))
                {
                    ++sim;
                }
            }
            else if (max(s.length(), d.length()) - min(s.length(), d.length()) == 1)
            {
                int i = 0, j = 0;
                int skip = 0;
                while (i < s.length() && j < d.length())
                {
                    if (s[i] != d[j])
                    {

                        if (skip == 1)
                        {
                            ++skip;
                            break;
                        }
                        else
                        {
                            ++skip;
                            if (s.length() < d.length())
                            {
                                ++j;
                            }
                            else
                            {
                                ++i;
                            }
                        }
                    }
                    else
                    {
                        ++i;
                        ++j;
                    }
                }
                if (skip <= 1)
                {
                    ++sim;
                }
            }
        }
        cout << sim << endl;
    }
    return 0;
}
