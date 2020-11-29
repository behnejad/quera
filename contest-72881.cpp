#include <iostream>

using namespace std;

int main()
{
    int n;
    double k, s;
    cin >> n >> k >> s;
    if ((n * k) > s)
    {
        cout << "Na! yeki bayad bere sabzi bekhare" << endl;
    }
    else
    {
        cout << "Kafie!" << endl;
    }
    return 0;
}
