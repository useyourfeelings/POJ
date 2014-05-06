#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;
bool isDag(vector<list<int> > adj, int n, vector<int> in)
{
    vector<int> incopy(in);
    deque<int> d;
    int get = 0;
    for(int i = 0; i < n; i++)
        if(incopy[i] == 0) d.push_back(i);
    while(!d.empty())
    {
        for(list<int>::iterator itr = adj[d.front()].begin();
                               itr != adj[d.front()].end(); itr ++)
        {
            if(--incopy[*itr] == 0)
            {
                d.push_back(*itr);
            }
        }
        d.pop_front();
        get ++;     
    }
    if(n == get) return 1;
    return 0;
}
int main()
{   
    static int n, m, in[26], time, i, j, num, t;
    char a, b, buff;
    while(cin>>n>>m && n != 0 && m != 0)
    {
        vector<int> ind(n);
        vector<char> done;
        vector<list<int> > adj(n);
        for(time = 1;; time ++)
        {
            cin>>a>>buff>>b;
            adj[int(b - 65)].push_back(int(a - 65));
            ind[int(a - 65)] ++;
            for(i = 0; i < n; i ++) cout<<ind[i]<<" ";
            cout<<endl;
            if(!isDag(adj, n, ind))
            {
                cout<<"Inconsistency found after "<<time<<" relations."<<endl;
                for(i = 0; i < m - time; i ++) cin>>a>>buff>>b;
                break;
            }
            vector<int> in(ind);
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
