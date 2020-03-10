#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    generate(a.begin(), a.end(), [](){int i; cin >> i; return i;});

    return 0;
}
