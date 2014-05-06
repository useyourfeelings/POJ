// 2243 Knight Moves     01_03_2007

#include<iostream>
#include<limits>
using namespace std;

int board[9][9];
int move[8][2] = {{-2, 1}, {-2, -1}, {-1, -2}, {1, -2},
                  {2, -1}, {2, 1}, {1, 2}, {-1, 2}};

void make(int ax, int ay, int step)
{
    if(step >= board[ax][ay]) return;
    board[ax][ay] = step;
    int min = INT_MAX, x, y, t, i;
    for(i = 0; i < 8; ++ i)
    {
        x = ax + move[i][0];
        y = ay + move[i][1];
        if(1 <= x && x <= 8 && 1 <= y && y <= 8)
            make(x, y, step + 1);
    }
}

int main()
{
    int ax, bx, ay, by, i, j;
    char at, bt;
    while(cin>>at>>ay>>bt>>by)
    {
        ax = int(at - 96);
        bx = int(bt - 96);
        for(i = 1; i < 9; ++ i)
            for(j = 0; j < 9; ++ j) board[i][j] = INT_MAX;
        make(ax, ay, 0);
        printf("To get from %c%d to %c%d takes %d knight moves.\n",
                                       at, ay, bt, by, board[bx][by]);
    }
    return 0;
}