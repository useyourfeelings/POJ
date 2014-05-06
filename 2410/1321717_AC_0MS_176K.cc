#include<iostream>
using namespace std;

char com[32][8];
char acc[8];

int main()
{
    int i = 0, v, pc;
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
                        for(i = 7; i >= 0; -- i)
                        {
                            if(acc[i] == '0')
                            {
                                acc[i] = '1';
                                break;
                            }
                            else acc[i] = '0';
                        }
                    }
                    else
                    {
                        for(i = 7; i >= 0; -- i)
                        {
                            if(acc[i] == '1')
                            {
                                acc[i] = '0';
                                break;
                            }
                            else acc[i] = '1';
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
                        for(i = 0; i < 8; ++ i)
                            if(acc[i] != '0') break;
                        if(i == 8)
                        {
                            pc = (int(com[pc][3]) - 48) * 16 +
                                 (int(com[pc][4]) - 48) * 8 +
                                 (int(com[pc][5]) - 48) * 4 +
                                 (int(com[pc][6]) - 48) * 2 +
                                 (int(com[pc][7]) - 48);
                        }
                        else
                        {
                            if(++ pc > 31) pc = 0;
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
                        for(i = 0; i < 8; ++ i) acc[i] = com[v][i];
                    }
                    else
                    {
                        for(i = 0; i < 8; ++ i) com[v][i] = acc[i];
                    }
                    if(++ pc > 31) pc = 0;
                }
            }
        }
        for(i = 0; i < 8; ++ i) printf("%c", acc[i]);
        printf("\n");
        i = 0;
    }
    return 0;
}