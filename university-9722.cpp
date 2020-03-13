#include <iostream>
#include <set>
#include <cmath>

using namespace std;

bool is_prime(long i)
{
    long a = sqrt(i);
    long j = 2;

    while (j <= a)
    {
        if (i % j == 0)
        {
            return false;
        }

        ++j;
    }

    return true;
}

void job(int i, int j, int depth)
{
    int temp = (i * 10);

    if (j < depth)
    {
        for (int k = 0; k < 10; ++k)
        {
             if (is_prime(temp))
             {
                 job(temp, j + 1, depth);
             }
             ++temp;
        }
    }
    else
    {
        cout << i << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    job(2, 1, n);
    job(3, 1, n);
    job(5, 1, n);
    job(7, 1, n);
    return 0;
}
