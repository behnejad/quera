#include <iostream>

using namespace std;

int main()
{
    int a, b, l;
    cin >> a >> b >> l;

    int time = 0;
    bool is_a = true;

    while (l--)
    {
        time += (is_a) ? a : b;
        is_a = !is_a;
    }

    cout << time << endl;
    return 0;
}
