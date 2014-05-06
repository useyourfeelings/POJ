#include<iostream>
#include<vector>
using namespace std;

int num;
bool done[1001];
void dfs(int id, vector<vector<int> > g)
{
    done[id] = 1;
    num ++;
    vector<int>::iterator itr = g[id].begin();
    vector<int>::iterator end = g[id].end();
    for(; itr != end; ++itr)
        if(!done[*itr]) dfs(*itr, g);
}

int main()
{   
    int v, e, t, a, b, i;
    cin>>t;
    while(t--)
    {
        cin>>v>>e;
        vector<vector<int> > g(v + 1);
        for(i = 1; i <= e; i++)
        {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(done, 0, sizeof(bool) * (v + 1));
        num = 0;
        dfs(1, g);
        if(num != v) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}