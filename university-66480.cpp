#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base_array[] = "0123456789ABCDEF";

int main()
{
    unsigned int n;
    int base, remain;
    scanf("%ud", &n);
    scanf("%d", &base);

    int remains[100];
    memset(remains, 0, sizeof(remains));
    int index = 0;

    while (n >= base)
    {
        remains[index++] = n % base;
        n /= base;
    }

    remains[index] = n % base;

    for (; index >= 0; --index)
    {
        printf("%c", base_array[remains[index]]);
    }
    printf("\n");

    return 0;
}