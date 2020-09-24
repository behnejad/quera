#include <iostream>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    int day[n], max = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> day[i];
    }

    int num = 1;

    for (int i = 1; i < n; i++)
    {

        if (day[i] == (day[i - 1] + 1))
        {
            num++;
        }
        else
        {
            num = 1;

        }
        if (num > max)
        {

            max = num;
        }
    }

    max += k;
    if (max > n)
    {
        max = n;
    }

    cout << max << endl;
    return 0;
}
