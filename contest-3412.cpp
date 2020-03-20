#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    deque<string> chair;
    string temp;
    char from;

    for (int i = 0; i < 4; ++i)
    {
        cin >> temp >> from;
        if (from == 'L')
        {
            chair.push_front(move(temp));
        }
        else if (from == 'R')
        {
            chair.push_back(move(temp));
        }
    }

    cout << chair[1] << endl;
    return 0;
}
