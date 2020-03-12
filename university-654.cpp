#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n < 12)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    else
    {
        int a = n >> 1;

        for (int i = 2; i < a; ++i)
        {
            long long j = i * i;
            long long k = n - i;
            long long k2 = k * k;
            long long i2k2 = (j + k2) * (j + k2);
            long long c2 = i2k2/ (k2 << 2);
            long double c = sqrt(c2);

            if (c == (long long) c)
            {
                int q = i;
                int w = c;
                int e = n - w - q;
                if (q > w)
                {
                    swap(q, w);
                }
                if (w > e)
                {
                    swap(w, e);
                }
                if (q > w)
                {
                    swap(q, w);
                }
                cout << q << " " << w << " " << e << endl;
                return 0;
            }
        }    
    }

    cout << "Impossible" << endl;
    return 0;
}
