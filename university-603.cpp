#include <iostream>

using namespace std;

int count = 0;

void job(int i, int depth)
{
    if (i == depth)
    {
        ++count;
        return;
    }
    if (i > depth)
    {
        return;
    }

    job(i + 1, depth);
    job(i + 2, depth);
    job(i + 5, depth);
}

int main()
{
    int n;
    cin >> n;

    job(0, n);

    cout << count << endl;
    return 0;
}
