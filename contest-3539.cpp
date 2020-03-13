#include <iostream>
#include <string>

using namespace std;

int main()
{
    int j = 0;
    string i;
    cin >> i;

    while (i.size() != 1)
    {
        j = 0;

        for (int k = 0; k < i.size(); ++k)
        {
            j += (i[k] - '0');
        }

        i = to_string(j);
    }

    cout << i << endl;
    return 0;
}
