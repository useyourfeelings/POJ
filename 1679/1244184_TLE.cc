#include<iostream>
#include<vector>
#include<list>
#include<limits>
using namespace std;
struct iw
{
    iw(int i, int w):id(i),wt(w){}
    int id;
    int wt;
};
struct uw
{
    uw():u(0){}
    int wt;
    bool u;
};
int maxv;
int maxw[101][101];
uw used[101][101];
void dfs(vector<list<iw> > mst, int head, vector<bool> & done, int id)
{
    done[id] = 1;
    list<iw>::iterator itr = mst[id].begin();
    list<iw>::iterator end = mst[id].end();
    for(; itr != end; ++itr)
    {
        int b = itr -> id;
        if(done[b]) continue;
        if(itr -> wt > maxv)
        {
            maxw[head][b] = itr -> wt;
            maxv = itr -> wt;
        }
        else maxw[head][b] = maxv;
        dfs(mst, head, done, b);
    }
}

int main()
{   
    int t, n, m, a, b, w, i;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<list<iw> > g(n + 1);
        for(i = 0; i < m; i++)
        {
            cin>>a>>b>>w;
            g[a].push_back(iw(b, w));
            g[b].push_back(iw(a, w));
            used[a][b].wt = w;
            used[b][a].wt = w;
        }
        
        vector<bool> done(n + 1, 0);
        vector<int> got;
        done[1] = 1;
        got.push_back(1);
        vector<list<iw> > mst(n + 1);
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
                list<iw>::iterator itrr = g[*itr].begin();
                list<iw>::iterator endd = g[*itr].end();
                for(; itrr != endd; ++itrr)
                {
                    if(done[itrr -> id]) continue;
                    if(itrr -> wt < minw)
                    {
                        minw = itrr -> wt;
                        willget = itrr -> id;
                        whoget = *itr;
                    }
                }
            }
            done[willget] = 1;
            mstwt += minw;
            got.push_back(willget);
            mst[whoget].push_back(iw(willget, minw));
            mst[willget].push_back(iw(whoget, minw));
            used[whoget][willget].u = 1;
            used[willget][whoget].u = 1;
        }
        for(i = 1; i <= n; i++)
        {
            done.assign(n + 1, 0);
            maxv = - 1;
            dfs(mst, i, done, i);
        }
        bool unique = 1;
        for(int i = 1; i<= n; i++)
        {
            list<iw>::iterator itr = g[i].begin();
            list<iw>::iterator end = g[i].end();
            for(; itr != end; ++itr)
            {
                if(!used[i][itr -> id].u)
                {
                    if(maxw[i][itr -> id] == used[i][itr -> id].wt)
                    {
                        unique = 0;
                        break;
                    }
                    used[itr -> id][i].u = 1;
                }
            }
            if(!unique) break;
        }
        if(unique) cout<<mstwt<<endl;
        else cout<<"Not Unique!"<<endl;
    }
    return 0;
}