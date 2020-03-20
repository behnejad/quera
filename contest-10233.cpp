#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    long i;
    string input;
    cin >> input;
    i = stol(input);
    sort(input.begin(), input.end());
    vector<long> permutate;
    do {
        permutate.push_back(stol(input));
    } while(next_permutation(input.begin(), input.end()));
    sort(permutate.begin(), permutate.end());
    for (long x : permutate)
    {
        if (x > i)
        {
            cout << x << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
