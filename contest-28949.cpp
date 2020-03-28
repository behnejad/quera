#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int times[24 * 60] = {0};
    int max = 0, n;
    int h, m, max_index = 0;
    int count = 0;
    char t;

    cin >> n;
    string temp;

    while (n--)
    {
        cin >> temp >> h >> t >> m >> t;
        times[(h * 60) + m] += (t == '+') ? 1 : -1;
    }

    for (int i = 0; i < sizeof(times) / sizeof(times[0]); ++i)
    {
        count += times[i];
        if (count > max)
        {
            max_index = i;
            max = count;
            m = i % 60;
            h = i / 60;
        }
    }
    if (times[max_index + 1] == 0)
    {
        ++m;
        if (m == 60)
        {
            m = 0;
            ++h;
        }
    }
    cout << setfill('0') << setw(2) << h << ":" <<
            setfill('0') << setw(2) << m << endl;
    return 0;
}
