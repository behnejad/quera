#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

#define e97 1000000007


int main()
{
    int n;
    char temp_char1, temp_char2;
    string temp_str, temp_str1, temp_str2, temp_str3;
    istringstream temp_line;
    ostringstream result;
    map<char, long long> vars;

    getline(cin, temp_str);
    n = stoi(temp_str);

    vector<pair<string, bool>> lines(n);
    for (int i = 0; i < n; ++i)
    {
        getline(cin, lines[i].first);
        lines[i].second = false;
    }

    int index = 0;
    while (index < n)
    {
        if (lines[index].second)
        {
            cout << -1 << endl;
            return 0;
        }

        lines[index].second = true;

        temp_line.clear();
        temp_line.str(lines[index].first);
        temp_line >> temp_str;

        if (temp_str == "cout")
        {
            temp_line >> temp_str1;
            if (isalpha(temp_str1[0]))
            {
                if (vars.count(temp_str1[0]))
                {
                    result << vars[temp_str1[0]] << endl;
                }
                else
                {
                    result << 0 << endl;
                }
            }
            else
            {
                result << temp_str1 << endl;
            }
        }
        else if (temp_str == "goto")
        {
            temp_line >> index;
            if (index > n)
            {
                cout << -1 << endl;
                return 0;
            }
            --index;
            --index;
        }
        else if (temp_str == "assign")
        {
            temp_line >> temp_str1 >> temp_char1 >> temp_str2 >> temp_char2 >> temp_str3;
            long long a, b;

            if (isalpha(temp_str2[0]))
            {
                if (vars.count(temp_str2[0]))
                {
                    a = vars[temp_str2[0]];
                }
                else
                {
                    a = 0;
                }
            }
            else
            {
                a = stoll(temp_str2);
            }

            if (isalpha(temp_str3[0]))
            {
                if (vars.count(temp_str3[0]))
                {
                    b = vars[temp_str3[0]];
                }
                else
                {
                    b = 0;
                }
            }
            else
            {
                b = stoll(temp_str3);
            }

            if (isalpha(temp_str1[0]))
            {
                vars[temp_str1[0]] = ((a % e97) + (b % e97)) % e97;
            }
        }

        ++index;
    }

    cout << result.str();

    return 0;
}
