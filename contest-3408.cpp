#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string temp;
    stack<string> words;
    while (n--)
    {
        cin >> temp;
        words.push(move(temp));
    }
    while (words.size())
    {
        cout << words.top() << " ";
        words.pop();
    }
    cout << endl;
    return 0;
}
