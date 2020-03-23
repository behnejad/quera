#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m, n, count;
    bool fix;
    vector<int> customer, temp;
    while (true)
    {
        count = 0;
        cin >> m >> n;

        if (m == 0 && n == 0)
        {
            break;
        }

        customer.clear();

        for (int i = 0; i < m; ++i)
        {
            int t;
            cin >> t;
            customer.push_back(t);
        }

        if (n == 0)
        {
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < n; ++i)
        {
            fix = true;

            for (int j = 0; j < m; ++j)
            {
                int t;
                cin >> t;

                if (t > customer[j])
                {
                    fix = false;
                }
            }

            if (fix)
            {
                ++count;
            }
        }

        cout << count << endl;
    }
    return 0;
}
