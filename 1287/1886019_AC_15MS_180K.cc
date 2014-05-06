#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int p[51], r[51];
int g[51][51];
const int INF = 200;

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
    int n, p, i, a, b, len, got;
    while(scanf("%d", &n) && n != 0)
    {
        scanf("%d", &p);
        if(n == 1)
        {
            printf("0\n");
            continue;
        }
        for(a = 1; a <= n; ++ a)
            for(b = a; b <= n; ++ b) g[a][b] = g[b][a] = INF;
        for(i = 0; i < p; ++ i)
        {
            scanf("%d%d%d", &a, &b, &len);
            if(g[a][b] > len) g[a][b] = g[b][a] = len;
        }
        vector<edge> e;
        e.reserve(p);
        for(a = 1; a < n; ++ a)
            for(b = a + 1; b <= n; ++ b)
            {
                if(g[a][b] != INF) e.push_back(edge(a, b, g[a][b]));
            }
        sort(e.begin(), e.end());
        InitSet(n);
        for(len = i = got = 0;; ++ i)
        {
            if(got == n - 1) break;
            a = Find(e[i].u);
            b = Find(e[i].v);
            if(a != b)
            {
                len += e[i].len;
                Union(a, b);
                ++ got;
            }
        }
        printf("%d\n", len);
    }
    return 0;
}