#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge
{
    edge(int w, int aa, int bb):wt(w),a(aa),b(bb){}
    int wt;
    int a;
    int b;
};

bool comp(const edge &a, const edge &b)
{
    return a.wt > b.wt;
}

int rank[751];
int p[751];
int x[751];
int y[751];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void link(int a, int b)
{
    if(rank[a] < rank[b]) p[a] = b;
    else p[b] = a;
    if(rank[a] == rank[b]) rank[a]++;
}

void unify(int a, int b)
{
    link(find(a), find(b));
}

int main()
{   
    int n, i, j, m, a, b, t;
    cin>>n;
    vector<edge> ve;
    ve.reserve(n * (n - 1) / 2);
    for(i = 1; i <= n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        p[i] = i;
        rank[i] = 0;
    }
    cin>>m;
    for(i = 0, t = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        if(find(a) != find(b))
        {
            unify(a, b);
            t ++;
        }
    }
    for(i = 1; i < n; i++)
    {
        for(j = i + 1; j <= n; j++)
        {
            ve.push_back(edge((x[i] - x[j]) * (x[i] - x[j]) +
                         (y[i] - y[j]) * (y[i] - y[j]), i, j));
        }
    }
    sort(ve.begin(), ve.end(), comp);
    if(t == n - 1) cout<<endl;
    while(t < n - 1)
    {
        vector<edge>::reverse_iterator itr = ve.rbegin();
        if(find(itr -> a) != find(itr -> b))
        {
            unify(itr -> a, itr -> b);
            cout<<itr -> a<<" "<<itr -> b<<endl;
            t ++;
        }
        ve.pop_back();
    }
    return 0;
}