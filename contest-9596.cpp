#include <iostream>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    a %= 2;
    b %= 2;
    c %= 2;
    if(a==0&&b==0&&c==1)
        cout << "NO NO YES" << endl;
    if(a==0&&b==1&&c==0)
        cout << "NO YES NO" << endl;
    if(a==1&&b==0&&c==0)
        cout << "YES NO NO" << endl;
    if(a==1&&b==1&&c==1)
        cout << "NO NO NO" << endl;
    if(a==0&&b==0&&c==0)
        cout << "NO NO NO" << endl;
    if(a==0&&b==1&&c==1)
        cout << "YES NO NO" << endl;
    if(a==1&&b==0&&c==1)
        cout << "NO YES NO" << endl;
    if(a==1&&b==1&&c==0)
        cout << "NO NO YES" << endl;

    return 0;
}
