#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define TIME(h, m) ((h * 60) + m)

int get_period_id(int time)
{
    if (time >= TIME(6, 30) && time <= TIME(10, 0))
    {
        return 1;
    }
    else if (time >= TIME(10, 1) && time <= TIME(16, 0))
    {
        return 2;
    }
    else if (time >= TIME(16, 1) && time <= TIME(19, 0))
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

int main()
{
    long long scores = 0;
    set<int> times;
    int n, h, m, first = 0, last = 0;
    scanf("%d", &n);

    while (n--)
    {
        scanf("%d:%d", &h, &m);
        times.insert(TIME(h, m));
    }

    for (int x : times)
    {
        int t = get_period_id(x);
        if (t != 0)
        {
            last = t;
        }

        if (first == 0 && last != 0)
        {
            first = t;
        }
    }

    if (first == last && first != 0)
    {
        switch(first)
        {
           case 1:
           case 3:
               scores = 24000;
               break;
           case 2:
               scores = 16800;
               break;
        }
    }
    else if (first == 1 && last == 2)
    {
        scores = 24000;
    }
    else if (first == 1 && last == 3)
    {
        scores = 36000;
    }
    else if (first == 2 && last == 3)
    {
        scores = 24000;
    }

    printf("%lld\n", scores);
    return 0;
}
