#include<iostream>
#include<cmath>
using namespace std;

char pic[1024][20];

void draw(int r, int c, int n)
{
    if(n == 1)
    {
        pic[r][c]     = pic[r + 1][c - 1] = '/';
        pic[r][c + 1] = pic[r + 1][c + 2] = '\\';
        pic[r + 1][c] = pic[r + 1][c + 1] = '_';
    }
    else
    {
        -- n;
        int t = int(pow(2.0, n));
        draw(r, c, n);
        draw(r + t, c - t, n);
        draw(r + t, c + t, n);
    }
}

int main()
{
    int n, i, j, R, C;
    while(scanf("%d", &n) && n != 0)
    {
        R = int(pow(2.0, n));
        C = int(pow(2.0, n + 1));
        for(i = 0; i < R; ++ i)
            for(j = 0; j < C; ++ j) pic[i][j] = ' ';
        draw(0, pow(2.0, n) - 1, n);
        j = int(pow(2.0, n));
        for(i = 0; i < R; ++ i)
        {
            for(j = 0; j < C; ++ j)
                printf("%c", pic[i][j]);
            printf("\n");
        }
    }
    return 0;
}