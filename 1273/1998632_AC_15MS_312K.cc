#include<iostream>
using namespace std;

int g[201][201];
int pre[201];
int done[201];
int n, a, i, j, k, flow, minflow, who;

bool dfs(int pos)
{
    if(pos == n) return true;
    for(int i = 1; i <= n; ++ i)
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
    done[1] = 1;
    for(i = 2; i <= n; ++ i) done[i] = 0;
    return dfs(1); 
}

void GetMin()
{
    minflow = 10000001;
    for(j = n;;)
    {
        i = pre[j];
        if(g[i][j] < minflow) minflow = g[i][j];
        if(i == 1) break;
        j = i; 
    }
}

void Update()
{
    for(j = n;;)
    {
        i = pre[j];
        g[i][j] -= minflow;
        g[j][i] += minflow;
        if(i == 1) break;
        j = i; 
    }
}

int main()
{
    while(scanf("%d%d", &a, &n) != EOF)
    {
        for(i = 1; i <= n; ++ i)
            for(j = 1; j <= n; ++ j) g[i][j] = 0;
        for(i = 0; i < a; ++ i)
        {
            scanf("%d%d%d", &j, &k, &who);
            g[j][k] += who;
        }
        flow = 0;
        while(find())
        {
            GetMin();
            Update();
            flow += minflow;
        }
        printf("%d\n", flow);
    }
    return 0;
}