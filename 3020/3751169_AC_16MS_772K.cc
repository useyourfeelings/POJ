#include<iostream>
using namespace std;

int id[41][12];
char g[41][12];
int matched[512], ylink[512];
int map[512][512];
int n, k, i, j, test, R, C, xsize, ysize;

int augment(int x)
{
    if(matched[x]) return 0;
    matched[x] = 1;
    for(int y = 1; y <= ysize; ++ y)
    {
        if(map[x][y] && (ylink[y] == 0 || augment(ylink[y])))
        {
            ylink[y] = x;
            return 1;
        }
    }
    return 0;
}

int maxmatch()
{
    for(i = 1; i <= ysize; ++ i) ylink[i] = 0;
    int match = 0;
    for(i = 1; i <= xsize; ++ i)
    {
        for(j = 1; j <= xsize; ++ j) matched[j] = 0;
        if(augment(i)) ++ match;
    }
    return match;
}

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d%d", &R, &C);
        for(i = 1; i <= R; ++ i)
            scanf("%s", g[i] + 1);
        xsize = ysize = 0;
        for(i = 1; i <= R; ++ i)
            for(j = 1; j <= C; ++ j)
                if(g[i][j] == '*')
                {
                    if((i + j) % 2 == 0) id[i][j] = ++ xsize;
                    else                 id[i][j] = ++ ysize;
                }
        for(i = 1; i <= xsize; ++ i)
            for(j = 1; j <= ysize; ++ j) map[i][j] = 0;
        for(i = 1; i <= R; ++ i)
        {
            for(j = 1; j <= C; ++ j)
            {
                if((i + j) % 2 == 0 && g[i][j] == '*')
                {
                    if(j < C && g[i][j + 1] == '*')
                        map[id[i][j]][id[i][j + 1]] = 1;
                    if(i < R && g[i + 1][j] == '*')
                        map[id[i][j]][id[i + 1][j]] = 1;
                    if(j > 1 && g[i][j - 1] == '*')
                        map[id[i][j]][id[i][j - 1]] = 1;
                    if(i > 1 && g[i - 1][j] == '*')
                        map[id[i][j]][id[i - 1][j]] = 1;
                }
            }
        }
        printf("%d\n", xsize + ysize - maxmatch());
    }
    return 0;
}