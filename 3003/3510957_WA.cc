#include<iostream>
using namespace std;

const int MAXHI = 1024; 
int climb[128];
int best[MAXHI][128];
char move[MAXHI][128];
int test, n;

int MinDistanceUp(int height, int pos) // return -1 if impossible
{
    if(pos == n)
    {
        if(height != 0) return MAXHI; // fail
        else            return 0;     // done
    }
    if(best[height][pos] != -2) return best[height][pos];
    int up = MinDistanceUp(height + climb[pos], pos + 1);
    int down;
    if(height >= climb[pos])
        down = MinDistanceUp(height - climb[pos], pos + 1);
    else down = MAXHI;
    if(up != MAXHI) up += climb[pos];
    if(down != MAXHI) down -= climb[pos];
    if(down < 0) down = 0;
    if(down > up)
    {
        down = up;
        move[height][pos] = 'U';
    }
    else if(up > down)
    {
        move[height][pos] = 'D';
    }
    best[height][pos] = down;
    return down;
}

void show()
{
    if(best[0][0] == MAXHI)
    {
        printf("IMPOSSIBLE\n");
        return;
    }
    for(int h = 0, p = 0; p < n; ++ p)
    {
        printf("%c", move[h][p]);
        if(move[h][p] == 'U') h += climb[p];
        else                  h -= climb[p];
    }
    printf("\n");
}

int main()
{
    int i, j;
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++ i)
            scanf("%d", &climb[i]);
        for(i = 0; i < MAXHI; ++ i)
            for(j = 0; j < n; ++ j)
                best[i][j] = -2;
        MinDistanceUp(0, 0);
        show();
    }
    return 0;
}