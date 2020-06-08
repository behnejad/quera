#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<unsigned long long> roof(n, 0);
    vector<unsigned long long> mins(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> roof[i];
    }

    unsigned long long local_min, temp;
    for (int i = 0; i < n; ++i)
    {
        local_min = (i + 1) * roof[i];

        for (int j = 0; j < i; ++j)
        {
            temp = mins[j] + ((i - j) * roof[i]);

            if (temp < local_min)
            {
                local_min = temp;
            }
        }

        mins[i] = local_min;
    }

    cout << mins[n - 1] << endl;
    return 0;
}
