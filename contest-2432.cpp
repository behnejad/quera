#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

const int base[4] = {2, 3, 5, 7};

bool isprime(long i)
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

int main()
{
    int n;
    cin >> n;

    if (n < 5)
    {
        cout << base[n - 1] << endl;
        return 0;
    }

    queue<long> sprimes;
    sprimes.push(2);
    sprimes.push(3);
    sprimes.push(5);
    sprimes.push(7);

    n -= 4;
    long head;
    bool cond = true;
    while (cond)
    {
        head = sprimes.front();
        sprimes.pop();

        head *= 10;

        for (int i = 1; i < 10; ++i)
        {
            ++head;
            if (isprime(head))
            {
                sprimes.push(head);
                --n;
                if (n == 0)
                {
                    cond = false;
                    break;
                }
            }
        }
    }

    cout << head << endl;
    return 0;
}
