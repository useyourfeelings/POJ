#include<iostream>
using namespace std;

int g[100][100];
char pre[100], pad;
char done[100];
char type[100]; // 0 line    1 station    2 consumer
int current[100], limit[100]; // current value & max value
int nodes, stations, consumers, lines;
int flow, minflow, target, source;

bool dfs(int pos)
{
    if(type[pos] == 2)  // reach a consumer
    {
        minflow = limit[pos] - current[pos];
        target = pos;
        return true;
    }
    for(int i = 0; i < nodes; ++ i)
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
    int i, j;
    for(i = 0; i < nodes; ++ i)
    {
        if(type[i] != 1) continue; // take a station to start
        for(j = 0; j < nodes; ++ j) done[j] = 0;
        done[i] = 1;
        if(dfs(i))
        {
            source = i;
            if(limit[i] - current[i] < minflow)
                minflow = limit[i] - current[i];
            return true;
        }
    }
    return false;
}

void GetMin()
{
    int i, j;
    for(j = target;;)
    {
        i = pre[j];
        if(g[i][j] < minflow) minflow = g[i][j];
        if(i == source) break;
        j = i; 
    }
}

void Update()
{
    int i, j;
    for(j = target;;)
    {
        i = pre[j];
        g[i][j] -= minflow;
        if(i == source) break;
        j = i; 
    }
    current[source] += minflow;
    current[target] += minflow;
    if(current[source] == limit[source]) type[source] = 0;
    if(current[target] == limit[target]) type[target] = 0;
}

int main()
{
    int i, j, a, b, c;
    while(scanf("%d%d%d%d", &nodes, &stations, &consumers, &lines) != EOF)
    {
        for(i = 0; i < nodes; ++ i)
            for(j = 0; j < nodes; ++ j) g[i][j] = 0;
        for(i = 0; i < nodes; ++ i) type[i] = current[i] = 0;
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
            type[a] = 1;
            limit[a] = c;
        }
        for(i = 0; i < consumers; ++ i)
        {
            while(scanf("%c", &pad) && pad != '(');
            scanf("%d)%d", &a, &c);
            type[a] = 2;
            limit[a] = c;
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