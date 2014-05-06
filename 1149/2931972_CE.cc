#include<iostream>
using namespace std;

int g[128][128], lastcustomer[1001], firstcustomer[1001], provide[1001];
char pre[128], pad;
char done[128], queue[128];
int house, customer, nodes;
int flow, minflow, s, t;
const int MAX = 2000000;

bool bfs()
{
    int start, end, newend, i, j, who;
    queue[0] = s;
    start = 0;
    end = 1;
    while(start != end)
    {
        newend = end;
        for(; start < end; ++ start)
        {
            who = queue[start];
            if(g[who][t] > 0)
            {
                pre[t] = who;
                return true;
            }
            for(i = 1; i < nodes - 1; ++ i)
            {
                if(done[i] || i == who) continue;
                if(g[who][i] > 0)
                {
                    pre[i] = who;
                    queue[newend ++] = i;
                    done[i] = 1;
                }
            }
        }
        end = newend;
    }
    return false;
}

bool find()
{
    for(int i = 0; i < nodes; ++ i) done[i] = 0;
    done[s] = 1;
    return bfs(); 
}

void GetMin()
{
    int i, j;
    minflow = MAX;
    for(j = t;;)
    {
        i = pre[j];
        if(g[i][j] < minflow) minflow = g[i][j];
        if(i == s) break;
        j = i; 
    }
}

void Update()
{
    int i, j;
    for(j = t;;)
    {
        i = pre[j];
        g[i][j] -= minflow;
        if(i == s) break;
        j = i; 
    }
}

int main()
{
    int i, j, a, b;
    scanf("%d%d", &house, &customer);
    {
        nodes = customer + 2;
        s = 0;
        t = nodes - 1;
        for(i = 0; i < nodes; ++ i)
            for(j = 0; j < nodes; ++ j) g[i][j] = 0;
        for(i = 1; i <= house; ++ i)
        {
            lastcustomer[i] = firstcustomer[i] = -1;
            fscanf(pf, "%d", &provide[i]);
        }
        for(i = 1; i <= customer; ++ i)
        {
            scanf("%d", &a);
            for(j = 0; j < a; ++ j)
            {
                scanf("%d", &b);
                if(lastcustomer[b] != -1) // not new
                {
                    g[lastcustomer[b]][i] = MAX;
                }
                else
                {
                    firstcustomer[b] = i;
                }
                lastcustomer[b] = i;
            }
            scanf("%d", &g[i][t]); // customer to sink
        }
        for(i = 1; i <= house; ++ i)
        {
            if(firstcustomer[i] != -1)
                g[s][firstcustomer[i]] += provide[i];
        }
        flow = 0;
        while(find())
        {
            GetMin();
            Update();
            flow += minflow;
        }
        printf("%d", flow);
    }
    return 0;
}