#include <iostream>

using namespace std;

int main()
{
   int a,b,l;
   cin >> a >> b >> l;
   cout << (l % 2 == 0) ? ((a + b) * (l / 2)) : (((a + b) * (l / 2)) + a)<< endl;
   return 0;
}
