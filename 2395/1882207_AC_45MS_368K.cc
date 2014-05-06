#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int p[10001], r[10001];
int graph[10001][10001];

struct edge
{
    edge(int uu, int vv, int l):u(uu),v(vv),len(l){}
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
    int n, i, j, got, t, len;
    vector<edge> e;
    scanf("%d%d", &n, &t);
    while(t --)
    {
        scanf("%d%d%d", &i, &j, &len);
        e.push_back(edge(i, j, len));
    }
    sort(e.begin(), e.end());
    InitSet(n);
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
    return 0;
}