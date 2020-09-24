#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, start = 200000, end = -1;
	cin >> n >> m;
	--n;

    int list[n][2];
    vector <int> num;

    for (int i = 0; i < n; i++)
	{
        cin >> list[i][0];
        cin >> list[i][1];

        if (list[i][1] < start)
		{
            start = list[i][1];
        }

        if (list[i][0] > end)
		{
            end = list[i][0];
        }
    }

    for (int i = 0; i < m; i++)
	{
        num.push_back(i + 1);
    }

    long long int halat = 0;

    for (int i = 0; i < start; i++)
	{
        halat += (m - end) + 1;
        if (num[i] > end)
		{
            halat -= (num[i] - end);
        }
    }

    cout << halat << endl;
	return 0;
}
