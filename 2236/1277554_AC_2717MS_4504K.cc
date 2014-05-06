#include<iostream>
#include<vector>
using namespace std;

int x[1002];
int y[1002];
bool ok[1002];

int p[1002];
int rank[1002];

int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void link(int x, int y)
{
    if(rank[x] > rank[y]) p[y] = x;
    else p[x] = y;
    if(rank[x] == rank[y]) rank[y] ++;
}

void unify(int x, int y)
{
    link(find(x), find(y));
}

int main()
{   
    int n, d, i, j;
    char c;
    cin>>n>>d;
    for(i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    for(i = 1; i <= n; i++) p[i] = i;
    vector<vector<int> > g(n + 1);
    memset(ok, 0, sizeof(bool) * (n + 1));
    for(i = 1; i <= n - 1; i++)
    {
        for(j = i + 1; j <= n; j++)
        {
            if( (x[i] - x[j]) * (x[i] - x[j]) +
                (y[i] - y[j]) * (y[i] - y[j]) <= d * d )
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    while(scanf("%1s", &c) == 1)
    {
        if(c == 'O')
        {
            scanf("%d", &i);
            ok[i] = 1;
            vector<int>::iterator itr = g[i].begin();
            vector<int>::iterator end = g[i].end();
            for(; itr != end; ++itr)
                if(ok[*itr]) unify(i, *itr);
        }
        else
        {
            scanf("%d%d", &i, &j);
            if(find(i) == find(j)) cout<<"SUCCESS"<<endl;
            else cout<<"FAIL"<<endl;
        }
    }
    return 0;
}