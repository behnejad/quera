#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    deque<char> m;
    string temp;

    getline(cin, temp);

    for (char x : temp)
    {
        m.push_back(x);
    }

    temp.clear();

    while (true)
    {
        cin >> temp;
        if (temp == "EXIT")
        {
            break;
        }
        else if (temp == "PRINT")
        {
            for (char x : m)
            {
                cout << x;
            }
            cout << endl;
        }
        else if (temp == "PUT")
        {
            int i;
            char c;
            cin >> i >> c;
            if (i >= 1 && i <= m.size())
            {
                m[i - 1] = c;
            }
        }
        else if (temp == "REVERSE")
        {
            if (m.size() > 0)
            {
                reverse(m.begin(), m.end());
            }
        }
        else if (temp == "SHRINK")
        {
            int n;
            cin >> n;
            if (n >= m.size())
            {
                m.clear();
            }
            else
            {
                while (n--)
                {
                    m.pop_back();
                }
            }
        }
        else if (temp == "EXTEND")
        {
            int n;
            cin >> n;
            if (n != 0)
            {
                while (n--)
                {
                    m.push_back('*');
                }
            }
        }
        else if (temp == "SHIFT-L")
        {
            int n;
            cin >> n;
            if (m.size() > 0)
            {
                while (n--)
                {
                    m.push_back(m.front());
                    m.pop_front();
                }
            }
        }
        else if (temp == "SHIFT-R")
        {
            int n;
            cin >> n;
            if (m.size() > 0)
            {
                while (n--)
                {
                    m.push_front(m.back());
                    m.pop_back();
                }
            }
        }
    }


    return 0;
}
