#include<iostream>
using namespace std;
char map[26][26];

int main()
{
    int r, c, i, j, useful, robot;
    for(i = 1; i <= 24; ++ i)
        for(j = 1; j <= 24; ++ j) map[i][j] = 0;
    while(scanf("%d%d", &r, &c))
    {
        if(r == -1 && c == -1) break;
        if(r == 0 && c == 0)
        {
            for(robot = 0;; ++ robot) // send robot
            {
                useful = 0;
                for(r = c = 1;;)
                {
                    if(r == 24)
                    {
                        for(i = c; i <= 24; ++ i)
                        {
                            if(map[24][i] == 1)
                            {
                                map[24][i] = 0; // clear
                                useful = 1;
                            }
                        }
                        break;
                    }
                    for(i = 24; i >= c; -- i) // serch column
                    {
                        if(map[r][i] == 1)
                        {
                            for(j = c; j <= i; ++ j) map[r][j] = 0; // clear
                            useful = 1;
                            break;
                        }
                    }
                    if(i < c) i = c;
                    c = i;
                    ++ r;
                }
                if(useful == 0) // did nothing
                {
                    printf("%d\n", robot);
                    break;
                }
            }
            for(i = 1; i <= 24; ++ i)
                for(j = 1; j <= 24; ++ j) map[i][j] = 0;
        }
        else map[r][c] = 1;
    }
    return 0;
}