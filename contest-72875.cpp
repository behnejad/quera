#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    if (n < 3)
    {
        cout << "Bah Bah! Ajab jooji!" << endl;
    }
    else
    {
        n -= 2;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] < arr[i + 1] && arr[i + 1] > arr[i + 2])
            {
                cout << "Ey baba :(" << endl;
                return 0;
            }
        }
        cout << "Bah Bah! Ajab jooji!" << endl;
    }

    return 0;
}
