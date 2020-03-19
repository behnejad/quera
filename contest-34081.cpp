#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int count = 1;
    int turn = k % n;
    while (turn != 0)
    {
        turn = (turn + k) % n;
        ++count;
    }

    cout << count << endl;
    return 0;
}
