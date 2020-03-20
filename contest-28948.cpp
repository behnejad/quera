#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string input, output;
    cin >> input;
    int back = 0;
    reverse(input.begin(), input.end());
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == '=')
        {
            ++back;
        }
        else if (back == 0)
        {
            output += input[i];
        }
        else
        {
            --back;
        }
    }

    reverse(output.begin(), output.end());
    cout << output << endl;
    return 0;
}
