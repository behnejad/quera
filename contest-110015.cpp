#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int t = 1;

    for (int i = 0; i < 4; ++i)
    {
        cout << "########.......########" << endl;
        if (n > 0)
        {
            cout << "#ghorfe" << t;
            --n;
            ++t;
        }
        else
        {
            cout << "#.......";
        }

        cout << ".......";

        if (n > 0)
        {
            cout << "ghorfe" << t << "#";
            --n;
            ++t;
        }
        else
        {
            cout << ".......#";
        }

        cout << endl;
    }

    cout << "#######################" << endl;

    return 0;
}
