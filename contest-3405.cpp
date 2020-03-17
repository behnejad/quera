#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int temp;
    stack<int> q;
    while (true)
    {
        cin >> temp;
        if (temp == 0)
        {
            break;
        }
        q.push(temp);
    }

    while (q.size())
    {
        cout << q.top() << endl;
        q.pop();
    }

    return 0;
}
