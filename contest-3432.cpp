#include <iostream>
#include <set>

using namespace std;

int main()
{
    int mostafa, javad;
    cin >> javad >> mostafa;
    set<long long> job_javad, job_mostafa;
    for (int i = 0; i < javad; ++i)
    {
        long long t ;
        cin >> t;
        job_javad.insert(t);
    }
    for (int i = 0; i < mostafa; ++i)
    {
        long long t ;
        cin >> t;
        job_mostafa.insert(t);
    }

    if (mostafa == javad)
    {
        bool equal = true;
        for (auto i : job_javad)
        {
            if (job_mostafa.count(i) == 0)
            {
                equal = false;
                break;
            }
        }

        cout << (equal ? "Both" : "None") << endl;
    }
    else if (mostafa < javad)
    {
        bool equal = true;
        for (auto i : job_mostafa)
        {
            if (job_javad.count(i) == 0)
            {
                equal = false;
                break;
            }
        }

        cout << (equal ? "Mostafa" : "None") << endl;
    }
    else
    {
        bool equal = true;
        for (auto i : job_javad)
        {
            if (job_mostafa.count(i) == 0)
            {
                equal = false;
                break;
            }
        }

        cout << (equal ? "Mohammad Javad" : "None") << endl;
    }
    return 0;
}
