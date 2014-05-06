#include<iostream>
using namespace std;
char map[50][50];
int move[5][2] = {{0, 0}, {0, 1}, {-1, 0}, {1, 0}, {0, -1}};
int turn[5] = {0, 3, 1, 4, 2};
int main()
{
    int test, N, L, r, c, i, dir;
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d%d", &N, &L);
        for(i = 0; i < N; ++ i)
            for(c = 0; c < N; ++ c) map[i][c] = 0;
        for(i = 0; i < L; ++ i)
        {
            scanf("%d%d", &c, &r);
            r = N - r;
            -- c;
            map[r][c] = 1;
        }
        scanf("%d%d", &c, &r);
        if(c == 0)
        {
            r = N - r;
            dir = 1;
        }
        else if(c == N + 1)
        {
            r = N - r;
            c = N - 1;
            dir = 4;
        }
        else if(r == 0)
        {
            r = N - 1;
            -- c;
            dir = 2;
        }
        else
        {
            r = 0;
            -- c;
            dir = 3;
        }
        for(;;)
        {
            if(c == -1)
            {
                c = 0;
                r = N - r;
                break;
            }
            else if(c == N)
            {
                c = N + 1;
                r = N - r;
                break;
            }
            else if(r == -1)
            {
                ++ c;
                r = N + 1;
                break;
            }
            else if(r == N)
            {
                ++ c;
                r = 0;
                break;
            }
            if(map[r][c] == 1) dir = turn[dir];
            r += move[dir][0];
            c += move[dir][1];
        }
        printf("%d %d\n", c, r);
    }
    return 0;
}