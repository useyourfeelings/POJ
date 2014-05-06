#include<iostream>
#include<vector>
using namespace std;

int rank[50001];
int p[50001];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void link(int a, int b)
{
    if(rank[a] < rank[b]) p[a] = b;
    else p[b] = a;
    if(rank[a] == rank[b]) ++ rank[a];
}

void unify(int a, int b)
{
    link(find(a), find(b));
}

int main()
{
    int c = 1, n, m, i, a, b, count, t;
    while(scanf("%d%d", &n, &m) && n != 0)
    {
        for(i = 1; i <= n; ++i)
        {
            p[i] = i;
            rank[i] = 0;
        }
        for(i = 0; i < m; ++ i)
        {
            scanf("%d%d", &a, &b);
            unify(a, b);
        }
        vector<bool> vb(n + 1, 0);
        for(count = 0, i = 1; i <= n; ++ i)
        {
            t = find(i);
            if(!vb[t])
            {
                ++ count;
                vb[t] = 1;
            }
        }
        printf("Case %d: %d\n", c, count);
        ++ c;
    }
    return 0;
}