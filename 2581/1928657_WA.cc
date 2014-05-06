#include<iostream>
using namespace std;

int num[4];
int val[4] = {25, 10, 5, 1};
int i, j, total;
char point;
int rec[4][501];

int make(int pos, int remain)
{
    if(pos >= 4) return -1;
    if(rec[pos][remain] != -2) return rec[pos][remain];
    int i, re, t, min = 101;
    for(i = num[pos]; i >= 0; -- i)
    {
        re = remain - i * val[pos];
        if(re == 0)
            if(i < min) min = i;
        else if(re > 0)
        {
            if((t = make(pos + 1, re)) != -1)
                if(t + i < min) min = t + i;
        }
    }
    if(min == 101) min = -1;
    rec[pos][remain] = min;
    return min;
}

int main()
{
    while(scanf("%d%c%d%d%d%d%d", &i, &point, &total,
                       &num[0], &num[1], &num[2], &num[3]) != EOF)
    {
        total += i * 100;
        for(i = 0; i < 4; ++ i)
            for(j = 1; j <= total; ++ j) rec[i][j] = -2;
        if(make(0, total) == -1) printf("NO EXACT CHANGE\n");
        else
        {
            for(i = 0; i < 4; ++ i)
            {
                printf("%d ", rec[i][total]);
                total -= val[i] * rec[i][total];
            }
        }
        printf("\n");
    }
    return 0;
}