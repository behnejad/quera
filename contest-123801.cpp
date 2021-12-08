#include <iostream>

using namespace std;

int main()
{
    int a[5];
    int b[5];
    int s;

    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    cin >> b[0] >> b[1] >> b[2] >> b[3] >> b[4];

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            s = (((a[(i + 1) % 5] + b[(j + 1) % 5]) % 10) * 100) + (((a[(i + 2) % 5] + b[(j + 2) % 5]) % 10) * 10) + ((a[(i + 3) % 5] + b[(j + 3) % 5]) % 10);
            if (s % 6 == 0)
            {
                cout << "Boro joloo :)" << endl;
                return 0;
            }
        }
    }

    cout << "Gir oftadi :(" << endl;

    return 0;
}
