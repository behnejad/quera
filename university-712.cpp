#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
//    scanf("%d", &n);
//    scanf("%d", &t);

//    vector<int> a;
    int * a = new int[n];
    for (int i = 1; i <= n; ++i)
    {
//        a.push_back(i);
        a[i - 1] = i;
    }

    char temp[30];
    string s;

    while (t--)
    {
//        scanf("%s", temp);

        cin >> s;
        if (s == "NAME")
        {
            int i;
//            scanf("%d", &i);
            cin >> i;
            cout << a[i - 1] << endl;
        }
        else if (s == "REV")
        {
            int start, end;
//            scanf("%d", &start);
//            scanf("%d", &end);
//            --start;
//            --end;
            cin >> start >> end;
//            reverse(a.begin() + i - 1, a.begin() + j - 1);
            reverse(a + start - 1, a + end);
//            while (start < end)
//            {
//                int temp = a[start];
//                a[start] = a[end];
//                a[end] = temp;
//                start++;
//                end--;
//            }
        }
    }

    delete[] a;
    return 0;
}
