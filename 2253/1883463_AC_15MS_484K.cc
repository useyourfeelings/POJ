#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int stone[200][2];
int p[200], r[200];

struct edge
{
    edge(int uu, int vv, double l):u(uu),v(vv),len(l){}
    int u;
    int v;
    double len;
};

bool operator<(const edge &a, const edge &b)
{
    return a.len < b.len;
}

void InitSet(int n)
{
    for(int i = 0; i < n; ++ i)
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
    vector<edge>::iterator itr;
    int n, i, j, test = 1;
    double fd;
    while(scanf("%d", &n) && n != 0)
    {
        vector<edge> e;
        e.reserve(n * (n - 1) / 2);
        InitSet(n);
        fd = -1;
        for(i = 0; i < n; ++ i)
        {
            scanf("%d%d", &stone[i][0], &stone[i][1]);
            for(j = i - 1; j >= 0; -- j)
                e.push_back(edge(i, j, sqrt(
                    (stone[i][0] - stone[j][0]) * (stone[i][0] - stone[j][0]) +
                    (stone[i][1] - stone[j][1]) * (stone[i][1] - stone[j][1]))));
        }
        sort(e.begin(), e.end());
        for(itr = e.begin();; ++ itr)
        {
            i = itr -> u;
            j = itr -> v;
            if(Find(i) != Find(j))
            {
                Union(i, j);
                if(itr -> len > fd) fd = itr -> len;
                if(Find(0) == Find(1)) break;
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", test ++, fd);
    }
    return 0;
}