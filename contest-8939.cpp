#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

bool compare(char * input, unsigned long long result)
{
    char temp[30] = {0};
    string t = to_string(result);
    const char * digits = t.c_str();
    char * sharp = strchr(input, '#');
    int i = 0, j = 0, i_end = strlen(input), j_end = strlen(digits);

    while (input[i] != '#' && input[i] != 0)
    {
        if (input[i] != digits[j])
        {
            return false;
        }

        ++i;
        ++j;
    }

    i = i_end - 1;
    j = j_end - 1;

    while (input[i] != '#' && i >= 0)
    {
        if (input[i] != digits[j])
        {
            return false;
        }

        --i;
        --j;
    }

    return true;
}

int main()
{
    unsigned long long temp;
    char a[30], b[30], c[30];
    scanf("%s + %s = %s", a, b, c);
    if (strchr(a, '#') != NULL)
    {
        temp = atoll(c) - atoll(b);
        if (compare(a, temp))
        {
            cout << temp << " + " << b << " = " << c << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else if (strchr(b, '#') != NULL)
    {
        temp = atoll(c) - atoll(a);
        if (compare(b, temp))
        {
            cout << a << " + " << temp << " = " << c << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else if (strchr(c, '#') != NULL)
    {
        temp = atoll(a) + atoll(b);
        if (compare(c, temp))
        {
            cout << a << " + " << b << " = " << temp << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
