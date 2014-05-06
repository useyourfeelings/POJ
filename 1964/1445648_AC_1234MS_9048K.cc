#include<iostream>

char g[1003][1003];
int e[1003][1003][2];

int main()
{
    int i, j, t, r, c, m, n, maxa, answer, mine;
    scanf("%d", &t);
    while(t --)
    {
        answer = 0;
        scanf("%d%d", &r, &c);
        for(i = 1; i <= r; ++ i)
            for(j = 1; j <= c; ++ j) std::cin>>g[i][j];
        for(j = c + 1; j >= 1; -- j) e[r + 1][j][0] = e[r + 1][j][1] = 0;
        for(i = r + 1; i >= 1; -- i) e[i][c + 1][0] = e[i][c + 1][1] = 0;
        for(i = r; i >= 1; -- i)
            for(j = c; j >= 1; -- j)
            {
                if(g[i][j] == 'R') e[i][j][0] = e[i][j][1] = 0;
                else
                {
                    e[i][j][0] = 1 + e[i + 1][j][0];
                    e[i][j][1] = 1 + e[i][j + 1][1];
                    maxa = 0;
                    mine = 1005;
                    for(m = 0; m < e[i][j][0]; ++ m)
                    {
                        if(e[i + m][j][1] < mine) mine = e[i + m][j][1];
                        if((m + 1) * mine > maxa) maxa = (m + 1) * mine;
                    }
                    if(maxa > answer) answer = maxa;
                }
            }
        printf("%d\n", answer * 3);
    }
    return 0;
}