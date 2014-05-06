#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
using namespace std;
short maxwt = 0x7FFF;
struct info
{
    info(short i, short p, short w, short s):id(i),pid(p),wt(w),swt(s){}
    short id;
    short pid;
    short wt;
    short swt;
};
struct priority
{
    bool operator()(const info &a, const info &b) const {return a.swt > b.swt;}
};
struct pri
{
    bool operator()(const deque<short> &a, const deque<short> &b) const
    {
        return a[2] < b[2];
    }
};
void make(vector<list<short> > &adj, short Org, short Dest,
                                           short n, vector<deque<short> > &vv)
{
    short i;
    info t(Org, Org, 0, 0);
    vector<short> wt(n + 1, maxwt);
    wt[Org] = 0;
    vector<short> p(n + 1);
    vector<bool> done(n + 1);
    priority_queue<info, vector<info>, priority> q;
    q.push(t);
    while(!q.empty())
    {
        t = q.top();
        if(done[t.id])
        {
            q.pop();
            continue;
        }
        p[t.id] = t.pid;
        q.pop();
        done[t.id] = 1;
        for(list<short>::iterator itr = adj[t.id].begin();
                                     itr != adj[t.id].end(); ++itr)
        {
            i = (*itr >> 5) + wt[t.id];
            if(i < wt[*itr & 0x1F])
            {
                wt[*itr & 0x1F] = i;
                p[*itr & 0x1F] = t.id;
            }
            if(!done[*itr & 0x1F])
                q.push(info((*itr & 0x1F), t.id, (*itr >> 5), i));
        }
    }
    deque<short> path;
    path.push_back(Dest);
    while(path.front() != Org)
    {
        path.push_front(p[path.front()]);
    }
    path.push_front(wt[Dest]);
    path.push_front(Dest);
    path.push_front(Org);
    vv.push_back(path);
}

int main()
{   
    ifstream cin("b.txt",ios::in);
    short Dest, Org, w, i, j, n;
    cin>>n;
    vector<list<short> > adj(n + 1);
    for(i = 1; i <= n; ++i)
    {
        for(j = 1; j <= n; ++j)
        {
            cin>>w;
            if(i == j) continue;
            if(w >= 0)
            {
                adj[i].push_back(w << 5 | j);
            }
        }
    }
    cout<<"Org Dest Time Path"<<endl;
    cin>>Dest;
    vector<deque<short> > vv;
    while(cin>>Org)
    {
        make(adj, Org, Dest, n, vv);
    }
    sort(vv.begin(), vv.end(), pri());
    for(vector<deque<short> >::iterator itr = vv.begin(); itr != vv.end(); ++itr)
    {
        for(deque<short>::iterator itrr = itr -> begin(); itrr != itr -> end(); ++itrr)
            cout<<*itrr<<" ";
        cout<<endl;
    }
    return 0;
}
