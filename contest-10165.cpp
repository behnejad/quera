#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second
{
    Pred p;
    bool operator()(const std::pair<T1,T2> & left, const std::pair<T1,T2> & right)
    {
        return p(left.first, right.first);
    }
};

int main()
{
    int n, aldangi = 0, len = numeric_limits<int>::max(), x;
    long long a;
    cin >> n;

    vector<pair<int, long long>> array(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> x >> a;
        array[i].first = x;
        array[i].second = a;
    }

    sort(array.begin(), array.end(), sort_pair_second<int, int, std::less_equal<int>>());

    set<long long> s;
    for (int i = 0; i < n; ++i)
    {
        s.clear();
        s.insert(array[i].second);

        for (int j = i; j < n; ++j)
        {
            s.insert(array[j].second);
            x = s.size();
            if (x > aldangi)
            {
                aldangi = x;
                len = array[j].first - array[i].first;
            }
            else if (x == aldangi)
            {
                if (len > (array[j].first - array[i].first))
                {
                    len = array[j].first - array[i].first;
                }
            }
        }
    }

    cout << len << endl;
    return 0;
}
