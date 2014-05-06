#include<iostream>
using namespace std;

int main()
{
    int i, j, n, t, q;
    unsigned int d[10001][32];
    for(i = 0; i < 10001; ++ i) for(j = 0; j < 32; ++ j) d[i][j] = 0;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i)
    {
        scanf("%d", &t);
        for(j = 0; j < t; ++ j)
        {
            scanf("%d", &q);
            d[q][i / 32] |= (1 << (i % 32));
        }
    }
    scanf("%d", &q);
    while(q --)
    {
        scanf("%d%d", &n, &t);
        for(i = 0; i < 32; ++ i) if((d[n][i] & d[t][i]) != 0) break;
        if(i < 32) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}