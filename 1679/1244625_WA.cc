#include<iostream>
#include<vector>
#include<limits>
using namespace std;

struct uw
{
    uw():u(0){}
    int wt;
    bool u;
};
uw g[101][101];
int mst[101][101];
int maxw[101][101];
bool done[101];
int maxv;
int n;
void dfs(int head, int id)
{
    done[id] = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(done[i] || g[id][i].wt == 0) continue;
        int y = g[id][i].wt;
        if(y > maxv)
        {
            maxw[head][i] = y;
            maxv = y;
        }
        else maxw[head][i] = maxv;
        dfs(head, i);
    }
}

int main()
{   
    int t, m, a, b, i, j;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(a = 0; a <= n; a++)
        {
            for(b = 0; b <= n; b++)
            {
                g[a][b].wt = mst[a][b] = 0;
                g[a][b].u = 0;
            }
        }
        for(i = 0; i < m; i++)
        {
            cin>>a>>b;
            cin>>g[a][b].wt;
            g[b][a].wt = g[a][b].wt;
        }
        vector<int> got;
        got.reserve(n + 1);
        done[1] = 1;
        for(i = 2; i < n; i++) done[i] = 0;
        got.push_back(1);
        int mstwt = 0;
        
        while(got.size() != n)
        {
            int minw = INT_MAX;
            int willget;
            int whoget;
            vector<int>::iterator itr = got.begin();
            vector<int>::iterator end = got.end();
            for(; itr != end; ++itr)
            {
                for(i = 1; i <= n; ++i)
                {
                    int y = g[*itr][i].wt;
                    if(done[i] || y == 0) continue;
                    if(y < minw)
                    {
                        minw = y;
                        willget = i;
                        whoget = *itr;
                    }
                }
            }
            done[willget] = 1;
            mstwt += minw;
            got.push_back(willget);
            mst[whoget][willget] = minw;
            mst[willget][whoget] = minw;
            g[whoget][willget].u = 1;
            g[willget][whoget].u = 1;
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++) done[j] = 0;
            maxv = - 1;
            dfs(i, i);
        }
        bool unique = 1;
        for(i = 1; i <= n; i++)
        {
            for(j = i + 1; j <= n; j++)
            {
                if(!g[i][j].u)
                {
                    if(maxw[i][j] == g[i][j].wt)
                    {
                        unique = 0;
                        break;
                    }
                }
            }
            if(!unique) break;
        }
        if(unique) cout<<mstwt<<endl;
        else cout<<"Not Unique!"<<endl;
    }
    return 0;
}