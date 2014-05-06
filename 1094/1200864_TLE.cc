#include<iostream>
#include<vector>
#include<list>
using namespace std;
bool dfs(vector<list<int> > adj, vector<bool> &pre, vector<bool> marked,
                                        int i, int n)
{
    if(pre[i]) return 1;
    if(marked[i]) return 0;
    marked[i] = 1;
    for(list<int>::iterator itr = adj[i].begin();itr != adj[i].end(); itr ++)
    {
        if(!pre[*itr])
            if(!dfs(adj, pre, marked, *itr, n)) return 0;
        for(int j = 0; j < n; j ++) if(marked[j]) pre[j] = 1;
        pre[i] = 0;
    }
    pre[i] = 1;
    return 1;
}
bool isDag(vector<list<int> > adj, int n)
{
    vector<bool> pre(n, 0);
    vector<bool> marked(n, 0);
    for(int i = 0; i < n; i ++)
    {
        if(!pre[i])
            if(!dfs(adj, pre, marked, i, n)) return 0;
    }
    return 1;
}
int main()
{   
    static int n, m, in[26], time, i, j, num, t;
    char a, b, buff;
    while(cin>>n>>m && n != 0 && m != 0)
    {
        vector<int> in(n);
        vector<char> done;
        vector<list<int> > adj(n);
        for(time = 1;; time ++)
        {
            cin>>a>>buff>>b;
            adj[int(b - 65)].push_back(int(a - 65));
            in[int(a - 65)] ++;
            if(!isDag(adj, n))
            {
                cout<<"Inconsistency found after "<<time<<" relations."<<endl;
                for(i = 0; i < m - time; i ++) cin>>a>>buff>>b;
                break;
            }
            for(i = 0, num = 0; i < n; i ++)
            {
                if(in[i] == 0)
                {
                    j = i;
                    if(++ num == 2) break;
                }
            }
            if(num == 2)
            {
                if(time == m)
                {
                    cout<<"Sorted sequence cannot be determined."<<endl;
                    break;
                }
                else continue;
            }            
            done.push_back(char(j + 65));
            in[j] = -1;
            while(done.size() != n)
            {
                num = 0;
                for(list<int>::iterator itr = adj[j].begin(); itr != adj[j].end(); itr ++)
                {
                    if(--in[*itr] == 0)
                    {
                        t = *itr;
                        if(++num == 2) break;
                    }
                }
                if(num == 2) break;
                j = t;
                done.push_back(char(j + 65));
            }
            if(num == 2)
            {
                if(time == m)
                {
                    cout<<"Sorted sequence cannot be determined."<<endl;
                    break;
                }
                else continue;
            }
            cout<<"Sorted sequence determined after "<<time<<" relations: ";
            for(i = n - 1; i >= 0; i--) cout<<done[i];
            cout<<"."<<endl;
            for(i = 0; i < m - time; i ++) cin>>a>>buff>>b;
            break;
        }
    }
    return 0;
}