#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, keyvan = 0, nezam = 0, shir = 0;
    string key;
    cin >> n >> key;

    for (int i = 0; i < n; ++i)
    {
        int temp = key[i] - '0';
        if ((i % 3) + 1 == temp)
        {
            ++nezam;
        }

        switch (i % 4)
        {
        case 0:
        case 2:
            if (temp == 2)
               ++shir;
            break;
        case 1:
            if (temp == 1)
               ++shir;
            break;
        case 3:
            if (temp == 3)
               ++shir;
            break;
        }

        switch(i % 6)
        {
        case 0:
        case 1:
            if (temp == 3)
               ++keyvan;
            break;
        case 2:
        case 3:
            if (temp == 1)
               ++keyvan;
            break;
        case 4:
        case 5:
            if (temp == 2)
               ++keyvan;
            break;
        }
    }

    int maxi = max(keyvan, max(shir, nezam));
    cout << maxi << endl;

    if (maxi == keyvan)
    {
        cout << "keyvoon" << endl;
    }

    if (maxi == nezam)
    {
        cout << "nezam" << endl;
    }

    if (maxi == shir)
    {
        cout << "shir farhad" << endl;
    }

    return 0;
}
