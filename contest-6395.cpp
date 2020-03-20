#include <iostream>

using namespace std;

int main()
{
    bool init = true;
    long long init_parch = 0, parch = 0;
    int n;
    cin >> n;
    while (n--)
    {
        long long i;
        cin >> i;
        if (init)
        {
            init = false;
            if (i > 0)
            {
                init_parch = i;
            }
            else
            {
                parch -= i;
            }
        }
        else
        {
            if (i < 0)
            {
                parch -= i;
            }
            else
            {
                if (parch >= i)
                {
                    parch -= i;
                }
                else
                {
                    init_parch += i - parch;
                    parch = 0;
                }
            }
        }
    }
    cout << init_parch << endl;
    return 0;
}
