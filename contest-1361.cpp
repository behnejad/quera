#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, c;
    cin >> n >> m >> c;

    vector<pair<int, int>> person_card(n); // number in card, final seat number
    vector<pair<bool, bool>> seats(n); // taken, visited

    for (int i = 0; i < n; ++i)
    {
        cin >> person_card[i].first;
        seats[i].first = false;
        seats[i].second = false;
    }

    for (int index, i = 0; i < n; ++i)
    {
        index = person_card[i].first - 1;
        if (seats[index].first == false)
        {
            seats[index].first = true;
            person_card[i].second = index + 1;
        }
        else
        {
            for (int j = 0; j < n; ++j)
            {
                seats[j].second = false;
            }

            seats[index].second = true;

            do
            {
                index += c;
                index %= n;
                if (seats[index].second == true)
                    break;
                if (seats[index].first == false)
                    break;
                seats[index].second = true;
            } while (true);

            if (seats[index].first == false)
            {
                seats[index].first = true;
                person_card[i].second = index + 1;
            }

            if (seats[index].second == true)
            {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    while (m--)
    {
        cin >> n;
        cout << person_card[n - 1].second << " ";
    }
    cout << endl;

    return 0;
}
