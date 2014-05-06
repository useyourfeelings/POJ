#include<iostream>
#include<vector>
using namespace std;

int g[201][201];
int d[201];
int pred[201];
int done[201];
int v, e, i, j, k, flow, minflow;

void GetExactDistanceLables()
{
    vector<int> done(v + 1, 0);
    vector<int> queue(v);
    int i, s, t, tt, step, who;
    s = 0;
    t = 1;
    done[v] = 1;
    queue[0] = v;
    step = 1;
    while(s < t)
    {
        tt = t;
        for(; s < t; ++ s)
        {
            who = queue[s];
            for(i = 1; i < v; ++ i)
            {
                if(done[i]) continue;
                if(g[i][who] != 0)
                {
                    queue[tt ++] = i;
                    d[i] = step;
                    done[i] = 1;
                }
            }
        }
        ++ step;
        t = tt;
    }
    d[v] = 0;
}

int HaveAdmissibleArc(int i)
{
    for(j = 1; j <= v; ++ j)
    {
        if(d[i] == (d[j] + 1) && g[i][j] > 0) return j;
    }
    return 0;
}

void retreat(int i)
{
    int mind = v, j;
    for(j = 1; j <= v; ++ j)
    {
        if(g[i][j] > 0)
        {
            if(d[j] < mind) mind = d[j];
        }
    }
    d[i] = mind + 1;
}

void augment()
{
    int node = v, minflow = 1000000000, t;
    for(;;)
    {
        if((t = g[pred[node]][node]) < minflow)
            minflow = t;
        if(pred[node] == 1) break;
        node = pred[node];
    }
    node = v;
    for(;;)
    {
        g[pred[node]][node] -= minflow;
        g[node][pred[node]] += minflow;
        if(pred[node] == 1) break;
        node = pred[node];
    }
    flow += minflow;
}

void ShortestAugmentingPath()
{
    GetExactDistanceLables();
    int i = 1, j;
    flow = 0;
    while(d[1] < v)
    {
        j = HaveAdmissibleArc(i);
        if(j != 0)
        {
            pred[j] = i;
            if(j == v)
            {
                augment();
                i = 1;
            }
            else i = j;
        }
        else
        {
            retreat(i);
            if(i != 1) i = pred[i];
        }
    }
}

int main()
{
    while(scanf("%d%d", &e, &v) != EOF)
    {
        for(i = 1; i <= v; ++ i)
            for(j = 1; j <= v; ++ j) g[i][j] = 0;
        for(i = 0; i < e; ++ i)
        {
            scanf("%d%d%d", &j, &k, &flow);
            g[j][k] += flow;
        }
        ShortestAugmentingPath();
        printf("%d\n", flow);
    }
    return 0;
}