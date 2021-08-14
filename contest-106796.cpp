#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    while (k--)
    {
        auto c = s[s.length() - 1];
        s.pop_back();
        s.insert(0, 1, c);

        for (auto &x : s)
        {
            if (x == 'z')
            {
                x = 'a';
            }
            else
            {
                x += 1;
            }
        }
    }

    cout << s << endl;

    return 0;
}
