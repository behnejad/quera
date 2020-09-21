#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, t;
    cin >> n;
    int count = 0;

    map<int, int> arr;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        if (arr.count(t))
        {
            ++arr[t];
        }
        else
        {
            arr[t] = 1;
        }
    }

    map<int, int>::iterator it = arr.begin(), last = arr.end();
    int edge = it->first;
    int ed_count = it->second;
    ++it;
    while (true)
    {
        if (it == last)
            break;
        if (edge + 1 == it->first)
        {
            count += ed_count * it->second;
        }
        edge = it->first;
        ed_count = it->second;
        ++it;
    }

    cout << count << endl;
    return 0;
}
