#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class player
{
public:
    string name;
    int price, speed, finish, defence;
};

class team
{
public:
    string name;
    int money;
    int wins = 0;
    int lose = 0;
    int draw = 0;
    vector<int> players;
};

vector<player> players;
vector<team> teams;

bool find_player(int i)
{
    for (team & t : teams)
        for (int p : t.players)
            if (p == i)
                return true;
    return false;
}

bool check_team(int i, int j)
{
    for (int p : teams[j].players)
        if (p == i)
            return true;
    return false;
}

int power(int t)
{
    int res = 0;
    vector<int> & p = teams[t].players;
    for (int i = 0; i < 11; ++ i)
    {
        res += players[p[i]].speed + players[p[i]].finish;
    }
    return res;
}

int power2(int t)
{
    int res = 0;
    vector<int> & p = teams[t].players;
    for (int i = 0; i < 11; ++ i)
    {
        res += players[p[i]].speed + players[p[i]].defence;
    }
    return res;
}

int main()
{
    string cmd, a, b, c;
    int i, j, k, t;

    while (true)
    {
        cin >> cmd;
        if (cmd == "new")
        {
            cin >> a;
            if (a == "player")
            {
                player p;
                cin >> p.name >> p.price >> p.speed >> p.finish >> p.defence;
                players.push_back(p);
            }
            else if (a == "team")
            {
                team t;
                cin >> t.name >> t.money;
                bool exist = false;
                for (team &x : teams)
                {
                    if (x.name == t.name)
                    {
                        exist = true;
                        break;
                    }
                }

                if (!exist)
                {
                    teams.push_back(t);
                }
            }
        }
        else if (cmd == "buy")
        {
            cin >> i >> j;
            if (i > players.size())
            {
                cout << "player with the id " << i << " doesnt exist" << endl;
            }
            else if (j > teams.size())
            {
                cout << "team with the id " << j << " doesnt exist" << endl;
            }
            else if (find_player(i - 1))
            {
                cout << "player already has a team" << endl;
            }
            else if(teams[j - 1].money < players[i - 1].price)
            {
                cout << "the team cant afford to buy this player" << endl;
            }
            else
            {
                teams[j - 1].money -= players[i - 1].price;
                teams[j - 1].players.push_back(i - 1);
                cout << "player added to the team succesfully" << endl;
            }
        }
        else if (cmd == "sell")
        {
            cin >> i >> j;
            if (j > teams.size())
            {
                cout << "team with the id " << j << " doesnt exist" << endl;
            }
            else if (!check_team(i - 1, j - 1))
            {
                cout << "team doesnt have this player" << endl;
            }
            else
            {
                teams[j - 1].money += players[i - 1].price;
                teams[j - 1].players.erase(std::remove(teams[j - 1].players.begin(), teams[j - 1].players.end(), i - 1), teams[j - 1].players.end());
                cout << "player sold succesfully" << endl;
            }
        }
        else if (cmd == "match")
        {
            cin >> i >> j;
            if (i > teams.size() || j > teams.size())
            {
                cout << "team doesnt exist" << endl;
            }
            else if (teams[i - 1].players.size() < 11 || teams[j - 1].players.size() < 11)
            {
                cout << "the game can not be held due to loss of the players" << endl;
            }
            else
            {
                int pi = power(i - 1), pj = power2(j - 1);
                if (pi == pj)
                {
                    teams[i - 1].draw += 1;
                    teams[j - 1].draw += 1;
                }
                else if (pi > pj)
                {
                    teams[i - 1].wins += 1;
                    teams[i - 1].money += 1000;
                    teams[j - 1].lose += 1;
                }
                else
                {
                    teams[i - 1].lose += 1;
                    teams[j - 1].wins += 1;
                    teams[j - 1].money += 1000;
                }
            }
        }
        else if (cmd == "rank")
        {
            vector<team> t = teams;
            sort(t.begin(), t.end(), [](team & a, team & b){
                if (a.wins > b.wins)
                    return true;
                else if (a.wins < b.wins)
                    return false;
                else if (a.lose < b.lose)
                    return true;
                else if (a.lose > b.lose)
                    return false;
                else
                    return false;
            });

            for (int i = 0; i < t.size(); ++i)
            {
                cout << i + 1 << ". " << t[i].name << endl;
            }
        }
        else if (cmd == "end")
        {
            break;
        }
    }

    return 0;
}
