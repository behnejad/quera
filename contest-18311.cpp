#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char times[24 * 60 * 60];
char correct[15 * 60];

int main()
{
    memset(times, 1, sizeof times);
    memset(correct, 1, sizeof correct);
    int i, start, end, h, m, s;

    scanf("%d", &i);
    while (i--)
    {
        scanf("%d:%d:%d", &h, &m, &s);
        start = h * 3600 + m * 60 + s;
        scanf("%d:%d:%d", &h, &m, &s);
        end = h * 3600 + m * 60 + s;
        memset(times + start, 0, end - start + 1);
    }

    scanf("%d", &i);
    while (i--)
    {
        scanf("%d:%d:%d", &h, &m, &s);
        start = h * 3600 + m * 60 + s;
        scanf("%d:%d:%d", &h, &m, &s);
        end = h * 3600 + m * 60 + s;
        memset(times + start, 0, end - start + 1);
    }

    scanf("%d", &i);
    while (i--)
    {
        scanf("%d:%d:%d", &h, &m, &s);
        start = h * 3600 + m * 60 + s;
        scanf("%d:%d:%d", &h, &m, &s);
        end = h * 3600 + m * 60 + s;
        memset(times + start, 0, end - start + 1);
    }

    bool found = false;
    for (size_t i = 0; i <= (24 * 60 * 60) - 15 * 60; ++i)
    {
        if (memcmp(times + i, correct, 15 * 60) == 0)
        {
            found = true;
            printf("%02d:%02d:%02d\n", i / 3600, (i % 3600) / 60, i % 60);
            break;
        }
    }

    if (found == false)
    {
        printf("-1\n");
    }
}
