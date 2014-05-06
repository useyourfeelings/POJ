#include<iostream>
#include<list>
using namespace std;

char com[32][8];
char acc[8];

int main()
{
    int i = 0, j, v, pc;
    bool c;
    while(scanf("%s", &com[i]) != EOF)
    {
        for(i = 1; i < 32; ++ i) scanf("%s", &com[i]);
        for(i = 0; i < 8; ++ i) acc[i] = '0';
        for(pc = 0;;)
        {
            if(com[pc][0] == '1')
            {
                if(com[pc][1] == '1')
                {
                    if(com[pc][2] == '1')
                    {
                        if(++ pc > 31) pc = 0;
                        break;
                    }
                    else
                    {
                        pc = (int(com[pc][3]) - 48) * 16 +
                             (int(com[pc][4]) - 48) * 8 +
                             (int(com[pc][5]) - 48) * 4 +
                             (int(com[pc][6]) - 48) * 2 +
                             (int(com[pc][7]) - 48);
                    }
                }
                else
                {
                    if(com[pc][2] == '1')
                    {
                        for(j = 7; j >= 0; -- j)
                        {
                            if(acc[j] == '0')
                            {
                                acc[j] = '1';
                                break;
                            }
                            else acc[j] = '0';
                        }
                    }
                    else
                    {
                        for(j = 7; j >= 0; -- j)
                        {
                            if(acc[j] == '1')
                            {
                                acc[j] = '0';
                                break;
                            }
                            else acc[j] = '1';
                        }
                    }
                    if(++ pc > 31) pc = 0;
                }
            }
            else
            {
                if(com[pc][1] == '1')
                {
                    if(com[pc][2] == '1')
                    {
                        if(++ pc > 31) pc = 0;
                        continue;
                    }
                    else
                    {
                        for(j = 0; j < 8; ++ j)
                            if(acc[j] != '0') break;
                        if(j == 8)
                        {
                            pc = (int(com[pc][3]) - 48) * 16 +
                                 (int(com[pc][4]) - 48) * 8 +
                                 (int(com[pc][5]) - 48) * 4 +
                                 (int(com[pc][6]) - 48) * 2 +
                                 (int(com[pc][7]) - 48);
                        }
                    }
                }
                else
                {
                    v = (int(com[pc][3]) - 48) * 16 +
                        (int(com[pc][4]) - 48) * 8 +
                        (int(com[pc][5]) - 48) * 4 +
                        (int(com[pc][6]) - 48) * 2 +
                        (int(com[pc][7]) - 48);
                    if(com[pc][2] == '1')
                    {
                        for(j = 0; j < 8; ++ j) acc[j] = com[v][j];
                    }
                    else
                    {
                        for(j = 0; j < 8; ++ j) com[v][j] = acc[j];
                    }
                    if(++ pc > 31) pc = 0;
                }
            }
        }
        for(j = 0; j < 8; ++ j) printf("%c", acc[j]);
        printf("\n");
    }
    return 0;
}