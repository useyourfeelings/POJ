#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int p[101], r[101];
int graph[101][101];

struct edge
{
    edge(int uu, int vv):u(uu),v(vv){len = graph[u][v];}
    int u;
    int v;
    int len;
};

bool operator<(const edge &a, const edge &b)
{
    return a.len < b.len;
}

void InitSet(int n)
{
    for(int i = 1; i <= n; ++ i)
    {
        p[i] = i;
        r[i] = 0;
    }
}

int Find(int x)
{
    if(p[x] != x) p[x] = Find(p[x]);
    return p[x];
}

void Link(int x, int y)
{
    if(r[x] > r[y]) p[y] = x;
    else            p[x] = y;
    if(r[x] == r[y]) ++ r[y];
}

void Union(int x, int y)
{
    Link(Find(x), Find(y));
}

int main()
{
    int n, len, i, j, got, t;
    scanf("%d", &n);
    InitSet(n);
    for(i = 1; i <= n; ++ i)
        for(j = 1; j <= n; ++ j) scanf("%d", &graph[i][j]);
    vector<edge> e;
    e.reserve(n * (n - 1) / 2);
    for(i = 1; i < n; ++ i)
        for(j = i + 1; j <= n; ++ j) e.push_back(edge(i, j));
    sort(e.begin(), e.end());
    scanf("%d", &t);
    for(got = 0; t > 0; -- t)
    {
        scanf("%d%d", &i, &j);
        if(Find(i) != Find(j))
        {
            Union(i, j);
            ++ got;
        }
    }
    for(len = t = 0;; ++ t)
    {
        if(got == n - 1) break;
        i = Find(e[t].u);
        j = Find(e[t].v);
        if(i != j)
        {
            len += e[t].len;
            Union(i, j);
            ++ got;
        }
    }
    printf("%d", len);
    return 0;
}