#include <iostream>

using namespace std;

int main()
{
    int king, minister, rock, bishop, knight, pown;
    cin >> king >> minister >> rock >> bishop >> knight >> pown;
    cout << (1 - king) << " " <<
            (1 - minister) << " " <<
            (2 - rock) << " " <<
            (2 - bishop) << " " <<
            (2 - knight) << " " <<
            (8 - pown) << endl;
    return 0;
}
