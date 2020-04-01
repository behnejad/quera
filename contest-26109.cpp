#include <iostream>

using namespace std;

int main()
{
    int p1, s1, p2, s2;
    cin >> p1 >> s1 >> s2 >> p2;

    if ((p1 + p2) > (s1 + s2))
    {
        cout << "Persepolis" << endl;
    }
    else if ((p1 + p2) < (s1 + s2))
    {
        cout << "Esteghlal" << endl;
    }
    else if (p2 > s1)
    {
        cout << "Persepolis" << endl;
    }
    else if (s1 > p2)
    {
        cout << "Esteghlal" << endl;
    }
    else
    {
        cout << "Penalty" << endl;
    }

    return 0;
}
