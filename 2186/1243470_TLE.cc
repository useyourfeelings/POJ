#include<iostream>
#include<vector>
#include<list>
using namespace std;

int n, m, i, j, k;
vector<list<int> > scc(1001);
int ingroup[1001];
bool done[1001];
vector<int> s;

bool okokok(int a, int b, vector<list<int> > g)
{
    list<int>::iterator itr = scc[b].begin();
    list<int>::iterator end = scc[b].end();
    for(; itr != end; ++itr) if(*itr == a) return 1;
    return 0;
}
bool okok(int a, int b, vector<list<int> > g)
{
    list<int>::iterator itr = g[a].begin();
    list<int>::iterator end = g[a].end();
    for(; itr != end; ++itr) if(okokok(*itr, b, g)) return 1;
    return 0;
}
bool ok(int a, int b, vector<list<int> > g)
{
    list<int>::iterator itr = scc[a].begin();
    list<int>::iterator end = scc[a].end();
    for(; itr != end; ++itr) if(okok(*itr, b, g)) return 1;
    return 0;
}
void dfs1(vector<list<int> > g, int id)
{
    done[id] = 1;
    list<int>::iterator itr = g[id].begin();
    list<int>::iterator end = g[id].end();
    for(; itr != end; ++itr)
        if(!done[*itr]) dfs1(g, *itr);
    s.push_back(id);
}

void dfs2(vector<list<int> > g, int id, int group)
{
    done[id] = 1;
    scc[group].push_back(id);
    ingroup[id] = group;
    list<int>::iterator itr = g[id].begin();
    list<int>::iterator end = g[id].end();
    for(; itr != end; ++itr)
        if(!done[*itr]) dfs2(g, *itr, group);
}

int main()
{   
    cin>>n>>m;
    vector<list<int> > g(n + 1);
    vector<list<int> > gt(n + 1);

    while(m--)
    {
        cin>>j>>k;
        g[j].push_back(k);
        gt[k].push_back(j);
    }
    
    for(j = 1; j <= n; j++) if(!done[j]) dfs1(g, j);
    for(j = 1; j <= n; j++) done[j] = 0;
    int group = 0;
    for(vector<int>::reverse_iterator itr = s.rbegin(); itr != s.rend(); ++itr)
        if(!done[*itr]) dfs2(gt, *itr, ++group);
    
    int win = 0;
    vector<bool> maybe(group + 1, 1);
    for(i = 1; i <= group; i++)
    {
        if(!maybe[i]) continue;
        for(j = 1; j <= group; j++)
        {
            if(i == j) continue;
            if(!ok(j, i, g)) break;
            maybe[j] = 0;
        }
        if(j > group)
        {
            win = i;
            break;
        }
    }
    
    if(win) cout<<scc[win].size()<<endl;
    else    cout<<0<<endl;
    return 0;
}