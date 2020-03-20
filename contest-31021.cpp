#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string t;
    if (n == 1)
    {
        cin >> t;
        cout << t << ": khodafez bacheha!" << endl;
    }
    else
    {
        vector<string> names;
        while (n--)
        {
            cin >> t;
            names.push_back(t);
        }

        for (int i = 1; i < names.size(); ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                cout << names[i] << ": salam " << names[j] << "!" << endl;
            }
        }

        for (int i = 0; i < names.size(); ++i)
        {
            cout << names[i] << ": khodafez bacheha!" << endl;

            for (int j = i + 1; j < names.size(); ++j)
            {
                cout << names[j] << ": khodafez " << names[i] << "!" << endl;
            }
        }
    }
    return 0;
}
