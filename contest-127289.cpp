#include <bits/stdc++.h>
using namespace std;

string s("codecup6");

int main()
{    
    int c;
    cin >> c;
    --c;
    cout << s[c % s.size()] << endl;
    return 0;
}
