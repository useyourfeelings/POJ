#include<iostream>
using namespace std;

int board[9][9];
int move[8][2] = {{-2, 1}, {-2, -1}, {-1, -2}, {1, -2},
                  {2, -1}, {2, 1}, {1, 2}, {-1, 2}};

int main()
{
    int ax, bx, ay, by, i, j, k, x, y, step;
    char at, bt;
    while(cin>>at>>ay>>bt>>by)
    {
        ax = int(at - 96);
        bx = int(bt - 96);
        step = 0;
        if(ax == bx && ay == by)
        {
            step = -1;
            goto DONE;
        }
        for(i = 1; i < 9; ++ i)
            for(j = 1; j < 9; ++ j) board[i][j] = -1;
        board[ax][ay] = 0;
        for(;;)
        {
            for(i = 1; i <= 8; ++ i)
                for(j = 1; j <= 8; ++j)
                {
                    if(board[i][j] != step) continue;
                    for(k = 0; k < 8; ++ k)
                    {
                        x = i + move[k][0];
                        y = j + move[k][1];
                        if(1 <= x && x <= 8 && 1 <= y && y <= 8)
                        {
                            board[x][y] = step + 1;
                            if(x == bx && y == by) goto DONE;
                        }
                    }
                }
            ++ step;
        }
        DONE :
        printf("To get from %c%d to %c%d takes %d knight moves.\n",
                                       at, ay, bt, by, step + 1);
    }
    return 0;
}