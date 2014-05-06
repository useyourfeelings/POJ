#include<iostream>
using namespace std;

int i, j, n, r, c, d;
char g[100][101], t[100][101];

bool win(int ii, int jj)
{
    if(g[i][j] == g[ii][jj]) return 0;
    switch(g[i][j])
    {
        case 'R': if(g[ii][jj] == 'P') return 1; break;
        case 'S': if(g[ii][jj] == 'R') return 1; break;
        case 'P': if(g[ii][jj] == 'S') return 1; break;
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    while(n --)
    {
        scanf("%d%d%d", &r, &c, &d);
        getchar();
        for(i = 0; i < r; ++ i) gets(g[i]);
        while(d --)
        {
            for(i = 0; i < r; ++ i)
            {
                for(j = 0; j < c; ++ j)
                {
                    if(i > 0)
                        if(win(i - 1, j))
                        {
                            t[i][j] = g[i - 1][j];
                            continue;
                        }
                    if(i < r - 1)
                        if(win(i + 1, j))
                        {
                            t[i][j] = g[i + 1][j];
                            continue;
                        }
                    if(j > 0)
                        if(win(i, j - 1))
                        {
                            t[i][j] = g[i][j - 1];
                            continue;
                        }
                    if(j < c - 1)
                        if(win(i, j + 1))
                        {
                            t[i][j] = g[i][j + 1];
                            continue;
                        }
                    t[i][j] = g[i][j];
                }
            }
            for(i = 0; i < r; ++ i)
                for(j = 0; j < c; ++ j) g[i][j] = t[i][j];
        }
        for(i = 0; i < r; ++ i)
        {
            for(j = 0; j < c; ++ j) printf("%c", g[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}