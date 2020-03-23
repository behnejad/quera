#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class logo
{
public:
    long long sum = 0;
    long long a = 0;
    long long b = 0;
    long long c = 0;
    logo() {};
};

int main()
{
    int n;
    long long max;
    map<int, logo> maps;
    vector<int> sor;
    vector<int> sor2;
    while (true)
    {
        maps.clear();
        sor.clear();
        sor2.clear();
        max = 0;
        cin >> n;

        if (n == 0)
        {
            break;
        }

        for (int i = 0; i < n; ++i)
        {
            int d;
            cin >> d;

            for (int j = 0; j < d; ++j)
            {
                int id;
                cin >> id;

                if (j == 0)
                {
                    ++maps[id].a;
                }
                else if (j == 1)
                {
                    ++maps[id].b;
                }
                else
                {
                    ++maps[id].c;
                }

                maps[id].sum += 3 - j;

                if (maps[id].sum > max)
                {
                    max = maps[id].sum;
                }
            }
        }

        for (pair<const int, logo> & x : maps)
        {
//            cout << "id: " << x.first << " a: " << x.second.a <<
//                    " b: " << x.second.b << " c: " << x.second.c <<
//                    " sum: " << x.second.sum << endl;
            if (x.second.sum == max)
            {
                sor.push_back(x.first);
            }
        }

        if (sor.size() == 1)
        {
            cout << sor[0] << endl;
        }
        else
        {
            int maxa = 0;
            for (int x : sor)
            {
                if (maps[x].a > maxa)
                {
                    maxa = maps[x].a;
                }
            }

            for (int x : sor)
            {
                if (maps[x].a == maxa)
                {
                    sor2.push_back(x);
                }
            }

            if (sor2.size() == 1)
            {
                cout << sor2[0] << endl;
            }
            else
            {
                sor.clear();
                int maxb = 0;

                for (int x : sor2)
                {
                    if (maps[x].b > maxb)
                    {
                        maxb = maps[x].b;
                    }
                }

                for (int x : sor2)
                {
                    if (maps[x].b == maxb)
                    {
                        sor.push_back(x);
                    }
                }

                sort(sor.begin(), sor.end());

                for (int a : sor)
                {
                    cout << a << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
