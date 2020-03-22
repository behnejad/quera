#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> array;

    while (n--)
    {
        int t;
        cin >> t;
        array.push_back(t);
    }

    int count = 0;
    n = array.size();

    for (int i = n - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (array[i] < array[j])
            {
                ++count;
            }
        }
    }

    cout << count % 100000 << endl;

    return 0;
}
