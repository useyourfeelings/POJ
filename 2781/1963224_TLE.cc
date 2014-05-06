#include<iostream>
#include<vector>
using namespace std;

int n, i, j, a, b, num, mindis, who;
char done[100000];
int dis[100000];
vector<vector<int> > g(100000);

void init()
{
    for(i = 0; i < n; ++ i)
    {
        dis[i] = 100001;
        done[i] = 0;
    }
    dis[a] = 0;
}

int Dijkstra()
{
    init();
    for(;;)
    {
        mindis = 100001;
        for(i = 0; i < n; ++ i)
        {
            if(done[i] != 0) continue;
            if(dis[i] < mindis)
            {
                mindis = dis[i];
                who = i;
            }
        }
        if(who == b) return mindis;
        done[who] = 1;
        for(j = g[who].size() - 1; j >= 0; -- j)
        {
            if(dis[g[who][j]] > dis[who] + 1)
                dis[g[who][j]] = dis[who] + 1;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(i = 0; i < n; ++ i)
    {
        scanf("%d%d", &who, &num);
        g[who].resize(num);
        for(j = 0; j < num; ++ j) scanf("%d", &g[i][j]);
    }
    scanf("%d%d", &a, &b);
    printf("%d %d %d", a, b, Dijkstra() - 1);
    return 0;
}