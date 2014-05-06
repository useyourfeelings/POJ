#include<iostream>
#include<algorithm>
using namespace std;

struct info
{
    char name[17];
    int a, b, cost;
};

bool comp(const info &a, const info &b)
{
    if(a.cost == b.cost) return a.name < b.name;
    return a.cost < b.cost;
}

info g[100];
int i, j, s, m, n, k, p;

int make(int id, int remain)
{
    if(remain == m) return 0;
    if(remain / 2 < m) return g[id].a * (remain - m);
    if((remain - remain / 2) * g[id].a > g[id].b)
        return g[id].b + make(id, remain / 2);
    return g[id].a + make(id, remain - 1);
}

int main()
{
    scanf("%d", &k);
    for(i = 1; i <= k; ++ i)
    {
        scanf("%d%d%d", &n, &m, &s);
        for(p = 0; p < s; ++ p)
        {
            for(j = 0;; ++ j)
            {
                scanf("%c", &g[p].name[j]);
                if(g[p].name[j] == ':')
                {
                    g[p].name[j] = 0;
                    break;
                }
            }
            scanf("%d,%d", &g[p].a, &g[p].b);
        }
        for(p = 0; p < s; ++ p) g[p].cost = make(p, n);
        sort(g, g + s, comp);
        printf("Case %d\n", i);
        for(j = 0; j < s; ++ j) printf("%s %d\n", g[j].name, g[j].cost);
        printf("\n");
    }
    return 0;
}
