#include<iostream>
using namespace std;

int pattern[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char map[24][24];
int R, C, startr, startc, best;

void move(int r, int c, int step, int p)
{
    if(step > 10) return; // fail
    int dr = pattern[p][0], dc = pattern[p][1];
    r += dr;
    c += dc;
    if(r < 0 || r >= R || c < 0 || c >= C) return; // out
    if(map[r][c] == '1') return;// blocked immediately
    if(map[r][c] == '3') // done
    {
        if(step < best) best = step;
        return;
    }
    for(;;)
    {
        r += dr;
        c += dc;
        if(r < 0 || r >= R || c < 0 || c >= C) return; // out
        if(map[r][c] == '3') // done
        {
            if(step < best) best = step;
            return;
        }
        if(map[r][c] == '1') break; // wall
    }
    map[r][c] = '0';
    for(int i = 0; i < 4; ++ i) move(r - dr, c - dc, step + 1, i);
    map[r][c] = '1';
}

int compute()
{
    best = 11;
    for(int i = 0; i < 4; ++ i)
    {
        move(startr, startc, 1, i);
    }
    if(best == 11) best = -1;
    return best;
}

int main()
{
    int i, j;
    while(scanf("%d%d\n", &C, &R) && C != 0)
    {
        for(i = 0; i < R; ++ i)
        {
            for(j = 0; j < C - 1; ++ j)
                scanf("%c ", &map[i][j]);
            scanf("%c\n", &map[i][j]);
        }
        for(i = 0; i < R; ++ i)
            for(j = 0; j < C; ++ j)
                if(map[i][j] == '2')
                {
                    startr = i;
                    startc = j;
                }
        printf("%d\n", compute());
    }
    return 0;
}