#include<iostream>
using namespace std;

int ylink[24];
int i, j, k, p, xsize, ysize;
int love[24][24];

int count(int id)
{
    if(id > xsize) return 1;
    int total = 0, i;
    for(i = love[id][0]; i >= 1; -- i)
    {
        if(ylink[love[id][i]]) continue; // matched
        ylink[love[id][i]] = 1;
        total += count(id + 1);
        ylink[love[id][i]] = 0;
    }
    return total;
}

int main()
{
    scanf("%d%d", &xsize, &ysize);
    for(i = 1; i <= xsize; ++ i)
    {
        scanf("%d", &k);
        love[i][0] = k;
        for(j = 1; j <= k; ++ j)
        {
            scanf("%d", &p);
            love[i][j] = p;
        }
    }
    memset(ylink, 0, sizeof(ylink));
    printf("%d\n", count(1));
    return 0;
}