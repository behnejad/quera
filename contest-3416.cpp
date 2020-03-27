#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    int i;

    while (n--)
    {
        cin >> i >> s;

        if (i == 1)
        {
            char last = 0;
            int count = 0;
            for (char k : s)
            {
                if (last == 0)
                {
                    last = k;
                    count = 1;
                }
                else if (k != last)
                {
                    cout << last;
                    if (count != 1)
                    {
                        cout << count;
                    }
                    last = k;
                    count = 1;
                }
                else
                {
                    ++count;
                }
            }

            cout << last;
            if (count != 1)
            {
                cout << count;
            }
            cout << endl;
        }
        else if (i == 2)
        {
            char last = 0;
            int count = 0;
            for (char j : s)
            {
                if (last == 0)
                {
                    last = j;
                    count = 0;
                }
                else if (j >= '0' && j <= '9')
                {
                    count *= 10;
                    count += j - '0';
                }
                else
                {
                    if (count != 0)
                    {
                        for (int i = 0; i < count; ++i)
                        {
                            cout << last;
                        }
                    }
                    else
                    {
                        cout << last;
                    }
                    count = 0;
                    last = j;
                }
            }
            if (count != 0)
            {
                for (int i = 0; i < count; ++i)
                {
                    cout << last;
                }
            }
            else
            {
                cout << last;
            }
            cout << endl;
        }
    }
    return 0;
}
