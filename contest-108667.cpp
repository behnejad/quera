#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

struct line
{
    string cmd;
    string username;
    string timestamp;
    string to_username;
    int amount;
    int value;
    int id;
    int org;
};

unordered_map<string, int> user_set;

vector<pair<int, int>> cash = {{100, 10}, {50, 10}, {10, 10}, {5, 10}, {1, 10}};

bool check_cash(int amount)
{
    for (auto & x : cash)
    {
        if (amount >= x.first)
        {
            int c = amount / x.first;
            amount -= min(c, x.second) * x.first;
        }
    }

    return amount == 0;
}

void withdraw_cash(int amount)
{
    for (auto & x : cash)
    {
        while (x.second > 0 && amount >= x.first)
        {
            --x.second;
            amount -= x.first;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<line> lines;
    vector<pair<int, string>> results;
    unordered_set<int> dos;
    line temp;

    for (int i = 0; i < n; ++i)
    {
        temp.id = i;
        temp.amount = 0;
        temp.value = 0;
        cin >> temp.cmd;
        if (temp.cmd == "REGISTER" || temp.cmd == "GET_BALANCE")
        {
            cin >> temp.username;
        }
        else if (temp.cmd == "DEPOSIT" || temp.cmd == "WITHDRAW")
        {
            cin >> temp.username >> temp.amount;
        }
        else if (temp.cmd == "TRANSFER")
        {
            cin >> temp.username >> temp.to_username >> temp.amount;
        }
        else if (temp.cmd == "ADD_BANKNOTE")
        {
            cin >> temp.value >> temp.amount;
        }
        cin >> temp.timestamp;
        if (temp.cmd == "TRANSFER")
        {
            line t2;
            t2.id = -1;
            t2.org = temp.id;
            t2.username = temp.to_username;
            t2.cmd = "DEPOSIT";
            t2.amount = temp.amount;
            int y, m, d, h, mi, s;
            sscanf(temp.timestamp.data(), "%d/%d/%d-%d:%d:%d", &y, &m, &d, &h, &mi, &s);
            h += 1;
            if (h >= 24)
            {
                h = 0;
                d += 1;
            }
            t2.timestamp.resize(20, 0);
            sprintf(t2.timestamp.data(), "%04d/%02d/%02d-%02d:%02d:%02d", y, m, d, h, mi, s);
            lines.push_back(t2);
        }
        lines.push_back(move(temp));
    }

    sort(lines.begin(), lines.end(), [](auto & a, auto & b){return a.timestamp.compare(b.timestamp) <= 0;});

    for (auto & x : lines)
    {
        // cout << x.timestamp << " - " << x.cmd << " - " << x.id << " - " << x.username << " - " << x.to_username << " - " << x.amount << endl;
        if (x.cmd == "REGISTER")
        {
            if (user_set.count(x.username))
            {
                results.push_back(make_pair(x.id, "Duplicate User!"));
            }
            else
            {
                user_set[x.username] = 100;
                results.push_back(make_pair(x.id, "Registered Successfully"));
            }
        }
        else if (x.cmd == "DEPOSIT")
        {
            if (x.id == -1 && dos.count(x.org) == 0)
            {
                continue;
            }
            if (user_set.count(x.username) == 0)
            {
                results.push_back(make_pair(x.id, "No Such User Found!"));
            }
            else
            {
                user_set[x.username] += x.amount;
                results.push_back(make_pair(x.id, to_string(user_set[x.username])));
            }
        }
        else if (x.cmd == "WITHDRAW")
        {
            if (user_set.count(x.username) == 0)
            {
                results.push_back(make_pair(x.id, "No Such User Found!"));
            }
            else if (x.amount > 200)
            {
                results.push_back(make_pair(x.id, "Maximum Amount Exceeded!"));
            }
            else if (x.amount > user_set[x.username])
            {
                results.push_back(make_pair(x.id, "Not Enough Fund!"));
            }
            else if (!check_cash(x.amount))
            {
                results.push_back(make_pair(x.id, "Not Enough Banknotes!"));
            }
            else
            {
                withdraw_cash(x.amount);
                user_set[x.username] -= x.amount;
                results.push_back(make_pair(x.id, to_string(user_set[x.username])));
            }
        }
        else if (x.cmd == "TRANSFER")
        {
            if (user_set.count(x.username) == 0 || user_set.count(x.to_username) == 0)
            {
                results.push_back(make_pair(x.id, "No Such User Found!"));
            }
            else if (x.amount > 3000)
            {
                results.push_back(make_pair(x.id, "Maximum Amount Exceeded!"));
            }
            else if (user_set[x.username] < x.amount)
            {
                results.push_back(make_pair(x.id, "Not Enough Fund!"));
            }
            else
            {
                dos.insert(x.id);
                user_set[x.username] -= x.amount;
                results.push_back(make_pair(x.id, to_string(user_set[x.username])));
            }
        }
        else if (x.cmd == "GET_BALANCE")
        {
            if (user_set.count(x.username) == 0)
            {
                results.push_back(make_pair(x.id, "No Such User Found!"));
            }
            else if (user_set[x.username] < 10)
            {
                results.push_back(make_pair(x.id, "Not Enough Fund!"));
            }
            else
            {
                user_set[x.username] -= 10;
                results.push_back(make_pair(x.id, to_string(user_set[x.username])));
            }
        }
        else if (x.cmd == "ADD_BANKNOTE")
        {
            for (auto & z : cash)
            {
                if (z.first == x.value)
                {
                    z.second += x.amount;
                }
            }

            results.push_back(make_pair(x.id, to_string(accumulate(cash.begin(), cash.end(), 0, [](auto a, auto b) {return a + (b.first * b.second);}))));
        }
    }

    sort(results.begin(), results.end(), [](auto & a, auto & b) {return a.first < b.first;});

    for (auto & x : results)
    {
        if (x.first != -1)
        {
            cout << x.second << endl;
        }
    }

    return 0;
}
