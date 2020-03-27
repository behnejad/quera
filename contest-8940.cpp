#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n, p, q;
    cin >> n >> p >> q;
    set<string> words;
    while (n--)
    {
        string i;
        cin >> i;
        string res = i.substr(0, p) + i.substr(i.size() - q, i.size());
        words.insert(move(res));
    }
    cout << words.size() << endl;
    return 0;
}
