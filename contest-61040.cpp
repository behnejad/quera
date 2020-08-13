#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define BLACK 1
#define WHITE 2

int map[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, WHITE, BLACK, 0, 0, 0},
    {0, 0, 0, BLACK, WHITE, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
};

int check_turn(int row, int column)
{
    return 0;
}

int main()
{
    int n;
    cin >> n;

    string move;
    int turn = BLACK;
    int r, c;

    while (n--)
    {
        cin >> move;
        r = move[1] - '1';
        c = move[0] - 'A';

        bool correct_turn = false;
        if (turn == BLACK)
        {

        }




    }

    int w = 0, b = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (map[i][j] == BLACK)
                ++b;
            else if (map[i][j] == WHITE)
                ++w;
        }
    }

    cout << b << " " << w << endl;

    return 0;
}
