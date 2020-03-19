#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k, count = 0;
    string pass, row;

    cin >> k;
    cin >> pass;

    for (int i = 0; i < k; ++i)
    {
        cin >> row;
        int index = row.find(pass[i]);
        if ((row.size() - index) < index)
        {
            count += row.size() - index;
        }
        else
        {
            count += index;
        }
    }

    cout << count << endl;

    return 0;
}
