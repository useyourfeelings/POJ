#include<iostream>

char map[1000][1001];

int main()
{
    int R, C, i, j, ir, ic, endr, endc, total;
    while(scanf("%d%d", &R, &C) && R != 0 && C != 0)
    {
        total = 0;
        for(i = 0; i < R; ++ i) scanf("%s", map[i]);
        for(ir = 0; ir < R; ++ ir)
        {
            for(ic = 0; ic < C; ++ ic)
            {
                if(map[ir][ic] == '.') continue;
                endr = ir + 1;
                endc = ic + 1;
                for(;;)
                {
                    if(endr >= R) break;
                    if(map[endr][ic] != '#') break;
                    ++ endr;
                }
                for(;;)
                {
                    if(endc >= C) break;
                    if(map[ir][endc] != '#') break;
                    ++ endc;
                }
                for(i = ir; i < endr; ++ i) // check inside
                {
                    for(j = ic; j < endc; ++ j)
                    {
                        if(map[i][j] != '#')
                        {
                            total = -1;
                            goto DONE;
                        }
                        else map[i][j] = '.';
                    }
                }
                if(endr < R)    // check bottom
                {
                    for(j = ic; j < endc; ++ j)
                    {
                        if(map[endr][j] == '#')
                        {
                            total = -1;
                            goto DONE;
                        }
                    }
                }
                if(endc < C)    // check right
                {
                    for(i = ir; i < endr; ++ i)
                    {
                        if(map[i][endc] == '#')
                        {
                            total = -1;
                            goto DONE;
                        }
                    }
                }
                if(ic > 0)    // check left
                {
                    for(i = ir; i < endr; ++ i)
                    {
                        if(map[i][ic - 1] == '#')
                        {
                            total = -1;
                            goto DONE;
                        }
                    }
                }
                ++ total; // got one
            }
        }
        DONE :
        if(total != -1) printf("There are %d ships.\n", total);
        else            printf("Bad placement.\n");
    }
    return 0;
}