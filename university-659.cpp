#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    deque<string> array;
    while (n > 0)
    {

        getline(cin, s);
        if (s.size() != 0)
        {
            --n;
            array.push_front(move(s));
        }
    }

    while (true)
    {
        getline(cin, s);
        if (s.size() != 0)
        {
            if (s == "Exit")
            {
                break;
            }
            else if (s == "DeleteLeft")
            {
                array.pop_back();
            }
            else if (s == "AddLeft")
            {
                while (true)
                {
                    getline(cin, s);
                    if (s.size() != 0)
                    {
                        array.push_back(move(s));
                        break;
                    }
                }
            }
            else if (s == "AddRight")
            {
                while (true)
                {
                    getline(cin, s);
                    if (s.size() != 0)
                    {
                        array.push_front(move(s));
                        break;
                    }
                }
            }
        }
    }

    cout << array.size() << endl;

    while (array.size())
    {
        cout << array.back() << endl;
        array.pop_back();
    }

    return 0;
}
