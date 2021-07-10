#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int counts [10];
    string first;
    string second;
    string temp;

    cin >> first;

    while (true)
    {
        memset(counts, 0, sizeof(counts));
        temp.clear();
        for (auto c : first)
        {
            ++counts[c - '0'];
        }

        for (auto c : first)
        {
            int count = counts[c - '0'];
            if (count == 1)
            {
                second += c;
                counts[c - '0'] = 0;
            }
            else if (count > 1)
            {
                second += c;
                temp += to_string(count);
                counts[c - '0'] = 0;
            }
        }

        second += temp;
        sort(second.begin(), second.end());

        if (second == first)
        {
            break;
        }
        else
        {
            first = move(second);
        }
    }

    cout << second << endl;

    return 0;
}
