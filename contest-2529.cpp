#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n, max = 0;
    string name;
    set<char> name_char;
    cin >> n;
    while (n--)
    {
        cin >> name;
        for (char x : name)
        {
            name_char.insert(x);
        }
        if (name_char.size() > max)
        {
            max = name_char.size();
        }
        name_char.clear();
    }
    cout << max << endl;
    return 0;
}
