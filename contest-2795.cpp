#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, c, p;
    cin >> n;
    vector<int> flors;
    while (n--)
    {
        cin >> c >> p;
        flors.clear();
        flors.resize(c, -1);

        while (p--)
        {
            int f, i;
            cin >> f >> i;
            flors[f - 1] = i;
        }

        bool success = true;
        for (int i = 0; i < c - 2 && success; ++i)
        {
            if (flors[i + 1] != -1)
            {
                if (flors[i] == 0 && flors[i + 1] == 1)
                {
                    success = false;
                }
                else if (flors[i] == 1 && flors[i + 1] == 0)
                {
                    success = false;
                }
            }
        }

        cout << (success ? "Yes" : "No") << endl;
    }

    return 0;
}
