#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int c, max = 1;
    cin >> c;
    map<string, int> names;
    while (c--)
    {
        string temp;
        cin >> temp;
        if (names.count(temp) == 0)
        {
            names[temp] = 1;
        }
        else
        {
            names[temp] += 1;
        }
        if (names[temp] > max)
        {
            max = names[temp];
        }
        cin >> temp;
    }

    cout << max << endl;
    return 0;
}
