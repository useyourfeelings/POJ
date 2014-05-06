#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int p[500], r[500];
int graph[500][500];

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
    int test, n, i, j, got, t;
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d", &n);
        InitSet(n);
        for(i = 0; i < n; ++ i)
            for(j = 0; j < n; ++ j) scanf("%d", &graph[i][j]);
        vector<edge> e;
        e.reserve(n * (n - 1) / 2);
        for(i = 0; i < n - 1; ++ i)
            for(j = i + 1; j < n; ++ j) e.push_back(edge(i, j));
        sort(e.begin(), e.end());
        for(got = t = 0; ; ++ t)
        {
            i = Find(e[t].u);
            j = Find(e[t].v);
            if(i != j)
            {
                Union(i, j);
                if(++ got == n - 1) break;
            }
        }
        printf("%d\n", e[t].len);
    }
    return 0;
}