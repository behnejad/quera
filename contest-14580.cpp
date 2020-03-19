#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, k, x;
    vector<string> channels;
    string temp;

    cin >> n >> x >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        channels.push_back(move(temp));
    }

    n = (x + k - 1) % n;

    cout << channels[n] << endl;

    return 0;
}
