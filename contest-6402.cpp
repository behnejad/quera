#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> names[i];
    }
    for (int i = 0; i < names.size() - 1; ++i)
    {
        cout << names[i] << " to " << names[i + 1] << ": ke ba in dar agar dar bande dar manand, dar manand." << endl;

        for (int j = i + 1; j > 0; --j)
        {
            cout << names[j] << " to " << names[j - 1] << ": dar manand?" << endl;
        }

        for (int j = 0; j <= i; ++j)
        {
            cout << names[j] << " to " << names[j + 1] << ": dar manand." << endl;
        }
    }
    return 0;
}
