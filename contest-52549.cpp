#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        map<long long, long long> scores;
        long long max = 0;

        while (n--)
        {
            int count;
            cin >> count;

            for (int i = 0; i < count; ++i)
            {
                int id;
                cin >> id;

                if (scores.count(id) == 0)
                {
                    scores[id] = 3 - i;
                }
                else
                {
                    scores[id] += 3 - i;
                }

                if (scores[id] > max)
                {
                    max = scores[id];
                }
            }
        }

        for (pair <long long, long long> x : scores)
        {
            if (x.second == max)
            {
                cout << x.first << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
