#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

vector<int> digits;
vector<int> digits2;
int sum1, m;

void print(vector<int> & a)
{
    for_each(a.begin(), a.end(), [](int i){cout << i;});
    cout << " ";
}

bool job_min(int index, int sum)
{
    for (int i = digits.size() - 1; i >= index; --i)
    {
        if (sum >= 10)
        {
            digits[i] = 9;
            sum -= 9;
        }
        else
        {
            digits[i] = sum;
            return true;
        }
    }
    return false;
}

bool job_max(int index, int sum)
{
    if (sum < 0)
    {
        return false;
    }

    for (int i = index; i < digits.size(); ++i)
    {
        if (sum >= 10)
        {
            digits[i] = 9;
            sum -= 9;
        }
        else
        {
            digits[i] = sum;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> m >> sum1;

    if (sum1 == 0 || m == 0 || sum1 > (m * 9))
    {
        cout << -1 << " " << -1 << endl;
    }
    else if (m == 1)
    {
        if (sum1 <= 9)
        {
            cout << sum1 << " " << sum1 << endl;
        }
        else
        {
            cout << -1 << " " << -1 << endl;
        }
    }
    else
    {
        bool has = false;

        digits.resize(m);
        for (int i = 1; i < 10; ++i)
        {
            digits[0] = i;
            if (job_min(1, sum1 - i))
            {
                has = true;
                digits2 = digits;
                print(digits);
                break;
            }
        }

        has = false;
        digits.clear();
        digits.resize(m);

        for (int i = 9; i > 0; --i)
        {
            digits[0] = i;
            if (job_max(1, sum1 - i))
            {
                has = true;
                print(digits);
                break;
            }
        }

        if (!has)
        {
            print(digits2);
        }
        cout << endl;
    }

    return 0;
}
