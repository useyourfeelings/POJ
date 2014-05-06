#include<iostream>
using namespace std;

int g[512][512];
int pre[512];
int done[512];
int cow, stall, i, j, k, flow, who;

bool dfs(int pos)
{
    int i, j;
    if(pos > 200)
    {
        if(g[pos][402] > 0)
        {
            pre[402] = pos;
            return true;
        }
        i = 1;
        j = cow;
    }
    else
    {
        i = 201;
        j = stall + 200;
    }
    for(; i <= j; ++ i)
    {
        if(done[i] || i == pos) continue;
        if(g[pos][i] > 0)
        {
            done[i] = 1;
            if(dfs(i))
            {
                pre[i] = pos;
                return true;
            }
        }
    }
    return false;
}

bool find()
{
    done[401] = 1;
    done[402] = 0;
    for(i = 1; i <= cow; ++ i) done[i] = 0;
    for(i = 200 + stall; i >= 201; -- i) done[i] = 0;
    return dfs(401); 
}


void Update()
{
    for(j = 402;;)
    {
        i = pre[j];
        g[i][j] -= 1;
        g[j][i] += 1;
        if(i == 401) break;
        j = i; 
    }
}

int main()
{
    while(scanf("%d%d", &cow, &stall) != EOF)
    {
        k = 200 + stall;
        for(i = 1; i <= cow; ++ i)
            for(j = 201; j <= k; ++ j) g[i][j] = g[j][i] = 0;
        for(i = 1; i <= cow; ++ i)
        {
            scanf("%d", &j);
            for(k = 0; k < j; ++ k)
            {
                scanf("%d", &who);
                g[i][who + 200] = 1;
            }
            g[401][i] = 1;
        }
        j = stall + 200;
        for(i = 201; i <= j; ++ i) g[i][402] = 1;
        flow = 0;
        while(find())
        {
            Update();
            ++ flow;
        }
        printf("%d\n", flow);
    }
    return 0;
}