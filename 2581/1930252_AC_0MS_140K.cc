#include<iostream>
using namespace std;

int num[4];
int val[4] = {25, 10, 5, 1};
int i, j, total;
char point;
int rec[4][501];//  minc
int give[4][501];// take

int make(int pos, int remain)
{
    if(pos >= 4) return -1;  // fail
    if(rec[pos][remain] != -2) return rec[pos][remain];
    int i, re, t, minc = 501, take;
    for(i = min(num[pos], remain / val[pos]); i >= 0; -- i)
    {
        re = remain - i * val[pos];
        if(re == 0)
        {
            if(i < minc)
            {
                minc = i;
                take = i;
            }
        }
        else if(re > 0)
        {
            if((t = make(pos + 1, re)) != -1)
                if((t + i) < minc)
                {
                    minc = t + i;
                    take = i;
                }
        }
    }
    if(minc == 501) take = minc = -1;
    rec[pos][remain] = minc;
    give[pos][remain] = take;
    return minc;
}

int main()
{
    while(scanf("%d%c%d%d%d%d%d", &i, &point, &total,
                       &num[0], &num[1], &num[2], &num[3]) != EOF)
    {
        total += i * 100;
        for(i = 0; i < 4; ++ i)
            for(j = 1; j <= total; ++ j) rec[i][j] = -2;
        if(make(0, total) == -1) printf("NO EXACT CHANGE");
        else
        {
            printf("%d", give[0][total]);
            total -= val[0] * give[0][total];
            for(i = 1; i < 4; ++ i)
            {
                printf(" %d", give[i][total]);
                total -= val[i] * give[i][total];
            }
        }
        printf("\n");
    }
    return 0;
}