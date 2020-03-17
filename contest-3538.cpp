#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<string> days;
    string temp;
    int count;

    cin >> count;
    while (count--)
    {
        cin >> temp;
        days.insert(move(temp));
    }


    cin >> count;
    while (count--)
    {
        cin >> temp;
        days.insert(move(temp));
    }


    cin >> count;
    while (count--)
    {
        cin >> temp;
        days.insert(move(temp));
    }

    cout << 7 - days.size() << endl;
    return 0;
}
