#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int count = s.size();
    for (int k = 0; k < count; ++k)
    {
        for (int i = 0; i < k; ++i)
        {
            s[i] = s[k];
        }

        cout << s << endl;
    }


    return 0;
}
