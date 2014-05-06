#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int p[1001], r[1001];

struct edge
{
    edge(int uu, int vv, int wt = 0):u(uu),v(vv),len(wt){}
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
    int i, n, p, a, b, len, got;
    scanf("%d%d", &n, &p);
    vector<edge> e;
    e.reserve(p);
    for(i = 0; i < p; ++ i)
    {
        scanf("%d%d%d", &a, &b, &len);
        e.push_back(edge(a, b, len));
    }
    sort(e.begin(), e.end());
    InitSet(n);
    vector<edge> cable;
    len = -1;
    for(i = got = 0;; ++ i)
    {
        if(got == n - 1) break;
        a = Find(e[i].u);
        b = Find(e[i].v);
        if(a != b)
        {
            cable.push_back(edge(e[i].u, e[i].v));
            if(e[i].len > len) len = e[i].len;
            ++ got;
            Union(a, b);
        }
    }
    printf("%d\n%d\n", len, cable.size());
    for(i = 0; i < cable.size(); ++ i) printf("%d %d\n", cable[i].u, cable[i].v);
    return 0;
}