#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>

using namespace std;

vector<string> screen;
pair<int, int> target;
bool no_target = false;
deque<pair<int, int>> snake;
enum {hup, hdown, hleft, hright};
int head_orient = hup;
int len = 1;

void print_screen()
{
    pair<int, int> head = snake.front();
    char t = screen[target.first][target.second];
    if (no_target == false)
    {
        screen[target.first][target.second] = 'A';
    }
    switch (head_orient)
    {
    case hup:
        screen[head.first][head.second] = '^';
        break;
    case hdown:
        screen[head.first][head.second] = 'v';
        break;
    case hleft:
        screen[head.first][head.second] = '<';
        break;
    case hright:
        screen[head.first][head.second] = '>';
        break;
    }
    for (string & x : screen)
    {
        cout << x << endl;
    }
    screen[target.first][target.second] = t;
}

int main()
{
    int n, m, t;
    cin >> n >> m >> t;

    string temp(m, '.');
    for (int i = 0; i < n; ++i)
    {
        screen.push_back(temp);
    }

    int sr, sc;
    cin >> sr >> sc;
    --sr;
    --sc;
    snake.push_back(pair(sr, sc));

    int p;
    cin >> p;
    queue<pair<int, int>> person;
    for (int i = 0; i < p; ++i)
    {
        int x, y;
        cin >> x >> y;
        person.push(pair(x - 1, y - 1));
    }

    if (p)
    {
        target = person.front();
        person.pop();
    }
    else
    {
        no_target = true;
    }

    int q;
    cin >> q;
    queue<pair<char, int>> command;
    for (int i = 0; i < q; ++i)
    {
        int t;
        char c;
        cin >> c >> t;
        command.push(pair(c, t));
    }

    for (int i = 0; i <= t; ++i)
    {
        if (command.front().second == i)
        {
            switch (command.front().first)
            {
            case 'L':
                switch (head_orient)
                {
                case hup:
                    head_orient = hleft;
                    break;
                case hdown:
                    head_orient = hright;
                    break;
                case hleft:
                    head_orient = hdown;
                    break;
                case hright:
                    head_orient = hup;
                    break;
                }
                break;
            case 'R':
                switch (head_orient)
                {
                case hup:
                    head_orient = hright;
                    break;
                case hdown:
                    head_orient = hleft;
                    break;
                case hleft:
                    head_orient = hup;
                    break;
                case hright:
                    head_orient = hdown;
                    break;
                }
                break;
            }

            command.pop();
        }

        pair<int, int> head = snake.front(), tail = snake.back();

        if (i != 0)
        {
            switch(head_orient)
            {
            case hup:
                if (head.first > 0)
                {
                    --head.first;
                }
                else
                {
                    head.first = n - 1;
                }
                break;
            case hdown:
                if (head.first < n - 1)
                {
                    ++head.first;
                }
                else
                {
                    head.first = 0;
                }
                break;
            case hleft:
                if (head.second > 0)
                {
                    --head.second;
                }
                else
                {
                    head.second = m - 1;
                }
                break;
            case hright:
                if (head.second < m - 1)
                {
                    ++head.second;
                }
                else
                {
                    head.second = 0;
                }
                break;
            }

            char & t = screen[head.first][head.second];
            if (t == '#')
            {
                if ((head_orient == hup || head_orient == hdown) && len > n)
                    break;
                if ((head_orient == hleft || head_orient == hright) && len > m)
                    break;
            }
            else if (target == head)
            {
                screen[snake.front().first][snake.front().second] = '#';
                snake.push_front(head);
                target = person.front();
                person.pop();
                if (person.size() == 0)
                {
                    no_target = true;
                }
                ++len;
            }
            else
            {
                screen[snake.front().first][snake.front().second] = '#';
                snake.push_front(head);
                snake.pop_back();
                screen[tail.first][tail.second] = '.';
            }
        }

        cout << i << endl;
        print_screen();
    }

    return 0;
}
