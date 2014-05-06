#include<iostream>
using namespace std;

char maze[1001][1001];
int R, C;

int make(int r, int c)
{
    if(maze[r][c] == '.')
    {
        maze[r][c] = 'G';
        int t, maxlen = 0, bestR = r, bestC = c;
        if((t = make(r + 1, c)) > maxlen)
        {
            maxlen = t;
            bestR = R;
            bestC = C;
        }
        if((t = make(r - 1, c)) > maxlen)
        {
            maxlen = t;
            bestR = R;
            bestC = C;
        }
        if((t = make(r, c + 1)) > maxlen)
        {
            maxlen = t;
            bestR = R;
            bestC = C;
        }
        if((t = make(r, c - 1)) > maxlen)
        {
            maxlen = t;
            bestR = R;
            bestC = C;
        }
        R = bestR;
        C = bestC;
        return maxlen + 1;
    }
    else return 0;
}

int main()
{
    int test, i, r, c, rr, cc;
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d%d", &c, &r);
        for(i = 0; i < r; ++ i) scanf("%s", maze[i]);
        rr = cc = 1;
        while(maze[rr][cc] != '.')
        {
            if(rr < r - 1) ++ rr;
            else
            {
                rr = 1;
                ++ cc;
            }
        }
        make(rr, cc);
        rr = cc = 1;
        for(rr = 1; rr < r - 1; ++ rr)
            for(cc = 1; cc < c - 1; ++ cc)
                if(maze[rr][cc] == 'G') maze[rr][cc] = '.';
        printf("Maximum rope length is %d.\n", make(R, C) - 1);
    }
    return 0;
}
