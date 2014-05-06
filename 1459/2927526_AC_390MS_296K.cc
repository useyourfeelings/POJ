#include<iostream>
using namespace std;

int g[102][102];
char pre[102], pad;
char done[102], queue[102];
int nodes, stations, consumers, lines;
int flow, minflow, s, t;

bool bfs()
{
    int start, end, newend, i, who;
    queue[0] = s;
    start = 0;
    end = 1;
    while(start != end)
    {
        newend = end;
        for(; start < end; ++ start)
        {
            who = queue[start];
            for(i = 0; i < nodes; ++ i)
            {
                if(i == who || done[i]) continue;
                if(g[who][i] > 0)
                {
                    pre[i] = who;
                    if(i == t) return true;
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
    minflow = 1000000;
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
    int i, j, a, b, c;
    while(scanf("%d%d%d%d", &nodes, &stations, &consumers, &lines) != EOF)
    {
        s = nodes;
        t = nodes + 1;
        nodes += 2;
        for(i = 0; i < nodes; ++ i)
            for(j = 0; j < nodes; ++ j) g[i][j] = 0;
        for(i = 0; i < lines; ++ i)
        {
            while(scanf("%c", &pad) && pad != '(');
            scanf("%d,%d)%d", &a, &b, &c);
            g[a][b] += c;
        }
        for(i = 0; i < stations; ++ i)
        {
            while(scanf("%c", &pad) && pad != '(');
            scanf("%d)%d", &a, &c);
            g[s][a] = c;
        }
        for(i = 0; i < consumers; ++ i)
        {
            while(scanf("%c", &pad) && pad != '(');
            scanf("%d)%d", &a, &c);
            g[a][t] = c;
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