#include<iostream>
using namespace std;

int n, a, b, i, j, num, mindis, who;
char g[101][101];
char done[101];
char dis[101];

void init()
{
    for(i = 1; i <= n; ++ i)
    {
        dis[i] = 2;
        done[i] = 0;
    }
    dis[a] = 0;
}

int Dijkstra()
{
    init();
    for(;;)
    {
        mindis = 3;
        for(i = 1; i <= n; ++ i)
        {
            if(done[i]) continue;
            if(dis[i] < mindis)
            {
                mindis = dis[i];
                who = i;
            }
        }
        if(mindis == 2) return -1;
        if(who == b) return mindis;
        done[who] = 1;
        if(g[who][0] != 0)
        {
            if(dis[g[who][1]] > dis[who])
                dis[g[who][1]] = dis[who];
        }
        for(j = g[who][0]; j >= 2; -- j)
        {
            if(dis[g[who][j]] > dis[who] + 1)
                dis[g[who][j]] = dis[who] + 1;
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for(i = 1; i <= n; ++ i)
    {
        scanf("%d", &num);
        g[i][0] = num;
        for(j = 1; j <= num; ++ j) scanf("%d", &g[i][j]);
    }
    printf("%d", Dijkstra());
    return 0;
}