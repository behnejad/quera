#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int k, a, b;
    cin >> k >> a >> b;
    int tak_tak_go = abs(b - a);
    int start_point_1 = 0, start_point_2 = 0;

    if (a >= 0)
    {
        start_point_1 = a + k - abs(a%k);
        start_point_2 = a - abs(a%k);
    }
    else
    {
        start_point_1 = a - a%k;
        start_point_2 = a -(k + a%k);
    }

    int end_point_1 = 0 ,end_point_2 =0;

    if (b >= 0)
    {
        end_point_1 = b + k - abs(b%k);
        end_point_2 = b - abs(b%k);
    }
    else
    {
        end_point_1 = b - b%k;
        end_point_2 = b -(k + b%k);
    }

    int oo1 = abs(start_point_1-end_point_1);
    int oo2 = abs(start_point_2-end_point_1);
    int oo3 = abs(start_point_2-end_point_2);
    int oo4 = abs(start_point_1-end_point_2);
    int arr[4];

    arr[0] = oo1;
    arr[1] = oo2;
    arr[2] = oo3;
    arr[3] = oo4;

    int s1,s2,e1,e2;
    sort(arr, arr + 4);

    if (arr[0] == oo1)
    {
        s1 = start_point_1;
        e1 = end_point_1;
        s2 = start_point_2;
        e2 = end_point_2;
    }
    else if (arr[0] == oo2)
    {
        s1 = start_point_2;
        e1 = end_point_1;
        s2 = start_point_1;
        e2 = end_point_2;
    }
    else if (arr[0] == oo3)
    {
        s1 = start_point_2;
        s2 = start_point_1;
        e1 = end_point_2;
        e2 = end_point_1;
    }
    else
    {
        s1 = start_point_1;
        s2 = start_point_2;
        e1 = end_point_2;
        e2 = end_point_1;
    }
    int d1 = abs(a-s1) + abs(b-e1) + abs(e1-s1)/k;
    int d2 = abs(a-s1) + abs(b-e2) + abs(e2-s1)/k;
    int d3 = abs(a-s2) + abs(b-e1) + abs(e1-s2)/k;
    int d4 = abs(a-s2) + abs(b-e2) + abs(e2-s2)/k;
    int arr2[4];

    arr2[0] = d1;
    arr2[1] = d2;
    arr2[2] = d3;
    arr2[3] = d4;
    sort(arr2, arr2 + 4);

    if (arr2[0] < tak_tak_go)
    {
        cout << arr2[0] << endl;
    }
    else
    {
        cout << tak_tak_go << endl;
    }

    return 0;
}
