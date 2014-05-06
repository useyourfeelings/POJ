#include<iostream>
#include<vector>
using namespace std;

int num;
bool done[1001];
void dfs1(int id, vector<vector<int> > g, vector<int> &f)
{
    done[id] = 1;
    vector<int>::iterator itr = g[id].begin();
    vector<int>::iterator end = g[id].end();
    for(; itr != end; ++itr)
        if(!done[*itr]) dfs1(*itr, g, f);
    f.push_back(id);
}

void dfs2(int id, vector<vector<int> > gt)
{
    done[id] = 1;
    num ++;
    vector<int>::iterator itr = gt[id].begin();
    vector<int>::iterator end = gt[id].end();
    for(; itr != end; ++itr)
        if(!done[*itr]) dfs2(*itr, gt);
}

int main()
{   
    int v, e, t, a, b, i;
    cin>>t;
    while(t--)
    {
        cin>>v>>e;
        vector<vector<int> > g(v + 1);
        vector<vector<int> > gt(v + 1);
        vector<int> f;
        for(i = 1; i <= e; i++)
        {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            gt[b].push_back(a);
        }
        memset(done, 0, sizeof(bool) * (v + 1));
        dfs1(1, g, f);
        num = 0;
        memset(done, 0, sizeof(bool) * (v + 1));
        dfs2(f.back(), gt);
        if(num != v) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}