#include <iostream>

using namespace std;

int main()
{
    int king, minister, rock, bishop, knight, pown;
    cin >> king >> minister >> rock >> bishop >> knight >> pown;
    cout << (king == 1 ? 0 : 1 - king) << " " <<
            (minister == 1 ? 0 : 1 - minister) << " " <<
            (rock == 2 ? 0 : 2 - rock) << " " <<
            (bishop == 2 ? 0 : 2 - bishop) << " " <<
            (knight == 2 ? 0 : 2 - knight) << " " <<
            (pown == 8 ? 0 : 8 - pown) << endl;
    return 0;
}
