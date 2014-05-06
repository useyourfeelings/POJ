#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int p[101], r[101];

struct edge
{
    edge(int uu, int vv, int wt):u(uu),v(vv),len(wt){}
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
    int i, test, n, m, a, b, len, got, lastlen, isUnique;
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d%d", &n, &m);
        if(n == 1)
        {
            printf("0\n");
            continue;
        }
        vector<edge> e;
        e.reserve(m);
        for(i = 0; i < m; ++ i)
        {
            scanf("%d%d%d", &a, &b, &len);
            e.push_back(edge(a, b, len));
        }
        sort(e.begin(), e.end());
        InitSet(n);
        for(len = i = got = 0;; ++ i)
        {
            a = Find(e[i].u);
            b = Find(e[i].v);
            if(a != b)
            {
                len += e[i].len;
                ++ got;
                if(got == n - 1)
                {
                    lastlen = e[i].len;
                    break;
                }
                Union(a, b);
            }
        }
        for(++ i; ; ++ i)
        {
            if(i >= e.size() || e[i].len > lastlen)
            {
                isUnique = 1;
                break;
            }
            m = Find(e[i].u);
            n = Find(e[i].v);
            if((m == a && n == b) || (m == b && n == a))
            {
                isUnique = 0;
                break;
            }
        }
        if(isUnique) printf("%d\n", len);
        else         printf("Not Unique!\n");
    }
    return 0;
}