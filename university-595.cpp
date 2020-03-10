#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    else if (n == 2)
    {
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    vector<vector<int>> pascal;

    vector<int> temp;
    temp.push_back(1);

    pascal.push_back(move(temp));

    temp.push_back(1);
    temp.push_back(1);

    pascal.push_back(move(temp));

    for (int i = 2; i < n; ++i)
    {
        temp.push_back(1);

        for (int k = 1; k < i; ++k)
        {
            temp.push_back(pascal.at(i - 1).at(k - 1) + pascal.at(i - 1).at(k));
        }

        temp.push_back(1);

        pascal.push_back(move(temp));
    }


    for (unsigned long long i = 0; i < pascal.size(); ++i)
    {
        temp = move(pascal.at(i));
        for (unsigned long long k = 0; k < temp.size(); ++k)
        {
            cout << temp.at(k) << " ";
        }
        cout << endl;
    }

    return 0;
}
