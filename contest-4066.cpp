#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<string, string> talks;
    string t1, t2;

    while (n--)
    {
        cin >> t1 >> t2;
        talks[move(t1)] = move(t2);
    }

    while (m--)
    {
        cin >> t1;
        if (talks.count(t1) == 0)
        {
            cout << "kachal! ";
        }
        else
        {
            cout << talks[t1] << " kachal! ";
        }
    }

    cout << endl;
    return 0;
}
