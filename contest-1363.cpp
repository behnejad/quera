#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define N 1000

int main()
{
    int n;
    cin >> n;

    vector<string> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int qm = 0, sm = 0, _m = 0;

                if (j > 0)
                {
                    if (a[i][j - 1] == '?')
                        ++qm;
                    if (a[i][j - 1] == '!')
                        ++sm;
                    if (a[i][j - 1] == '_')
                        ++_m;
                }

                if (j < n - 1)
                {
                    if (a[i][j + 1] == '?')
                        ++qm;
                    if (a[i][j + 1] == '!')
                        ++sm;
                    if (a[i][j + 1] == '_')
                        ++_m;
                }

                if (i > 0)
                {
                    if (a[i - 1][j] == '?')
                        ++qm;
                    if (a[i - 1][j] == '!')
                        ++sm;
                    if (a[i - 1][j] == '_')
                        ++_m;
                }

                if (i < n - 1)
                {
                    if (a[i + 1][j] == '?')
                        ++qm;
                    if (a[i + 1][j] == '!')
                        ++sm;
                    if (a[i + 1][j] == '_')
                        ++_m;
                }

                if (i > 0 && j > 0)
                {
                    if (a[i - 1][j - 1] == '?')
                        ++qm;
                    if (a[i - 1][j - 1] == '!')
                        ++sm;
                    if (a[i - 1][j - 1] == '_')
                        ++_m;
                }

                if (i > 0 && j < n - 1)
                {
                    if (a[i - 1][j + 1] == '?')
                        ++qm;
                    if (a[i - 1][j + 1] == '!')
                        ++sm;
                    if (a[i - 1][j + 1] == '_')
                        ++_m;
                }

                if (i < n - 1 && j > 0)
                {
                    if (a[i + 1][j - 1] == '?')
                        ++qm;
                    if (a[i + 1][j - 1] == '!')
                        ++sm;
                    if (a[i + 1][j - 1] == '_')
                        ++_m;
                }

                if (i < n - 1 && j < n - 1)
                {
                    if (a[i + 1][j + 1] == '?')
                        ++qm;
                    if (a[i + 1][j + 1] == '!')
                        ++sm;
                    if (a[i + 1][j + 1] == '_')
                        ++_m;
                }

                int k = qm + sm;
                if (a[i][j] == '_' && k == 3)
                {
                    b[i][j] = (qm > sm) ? '?' : '!';
                }
                else if ((a[i][j] == '?' || a[i][j] == '!') && (k < 2 || k > 3))
                {
                    b[i][j] = '_';
                }
                else if (a[i][j] == '!' && (k == 3 || k == 2) && (qm > sm))
                {
                    b[i][j] = '?';
                }
                else if (a[i][j] == '?' && (k == 3 || k == 2) && (sm > qm))
                {
                    b[i][j] = '!';
                }
                else
                {
                    b[i][j] = a[i][j];
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            a[i] = b[i];
        }
    }

    int q = 0, s = 0;
    for (int i = 0; i < n; ++i)
    {
        for (char c : a[i])
        {
            if (c == '?')
                ++q;
            else if (c == '!')
                ++s;
        }
    }

    cout << q << endl << s << endl;

    return 0;
}
