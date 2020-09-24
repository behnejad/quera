#include <iostream>
#include <string>

using namespace std;

int main(){

    int n;
    string t;
    cin >> n >> t;

    for (int i = 0; i < n; i++)
    {
        string code;
        cin >> code;
        bool code_situation = true;

        for (int j = 0; j < code.size(); j++)
        {
            bool character = false;
            for (int k = 0; k < t.size(); k++)
            {
                if (code[j] == t[k])
                {
                    character = true;
                }
            }

            if (not character)
            {
                code_situation = false;
            }
        }

        for (int j = 0; j < t.size(); j++)
        {
            bool character = false;
            for (int k = 0; k < code.size(); k++)
            {
                if (t[j] == code[k])
                {
                    character = true;
                }
            }

            if (not character)
            {
                code_situation = false;
            }
        }

        cout << ((code_situation) ? "Yes" : "No") << endl;
    }

    return 0;
}
