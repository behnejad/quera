#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, max = 0;
    cin >> n;
    vector<int> a(n);
    generate(a.begin(), a.end(), [](){int i; cin >> i; return i;});
    for (int i = 0; i < a.size() - 1; ++i)
    {
        int min = numeric_limits<int>::max();

        for (int j = i + 1; j < a.size(); ++j)
        {
            if (a[j] == 0)
            {
                i = j;
                break;
            }
            if (min > a[j])
            {
                min = a[j];
            }

            long area = (j - i) * min;
            if (max < area)
            {
                max = area;
            }
        }
    }

    cout << max << endl;
    return 0;
}
