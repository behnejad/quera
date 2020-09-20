#include <iostream>
#include <string>

using namespace std;

string s;
int sl;
int ip[4];

void job(int index, int lengh)
{
    if (index >= sl)
        return;
    if (lengh == 3)
    {
        if (sl - index > 3)
            return;
        if (sl - index != 1 && s[index] == '0')
            return;

        ip[lengh] = 0;
        while (index < sl)
        {
            ip[lengh] *= 10;
            ip[lengh] += (s[index] - '0');
            ++index;
        }

        if (ip[lengh] < 256)
        {
            cout << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3] << endl;
        }
        return;
    }

    if (s[index] == '0')
    {
        ip[lengh] = 0;
        job(index + 1, lengh + 1);
    }
    else
    {
        ip[lengh] = 0;
        for (int i = 0; i < 3; ++i)
        {
            ip[lengh] *= 10;
            ip[lengh] += (s[index + i] - '0');
            if (ip[lengh] < 256)
            {
                job(index + i + 1, lengh + 1);
            }
        }
    }
}

int main()
{
    cin >> s;
    if (s.length() < 4 || s.length() > 12)
        return 0;
    sl = s.length();
    job(0, 0);
    return 0;
}
