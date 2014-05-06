#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{   
    int group[100001];
    int t, n, m, a, b, i;
    char c;
    cin>>t;
    while(t--)
    {
        vector<list<int> > vli;
        cin>>n>>m;
        for(i = 1; i <= n; i++) group[i] = -1;
        while(m--)
        {
            cin>>c>>a>>b;
            if(c == 'A')
            {
                if(group[a] == -1 || group[b] == -1) cout<<"Not sure yet."<<endl;
                else if(group[a] == group[b]) cout<<"In the same gang."<<endl;
                else cout<<"In different gangs."<<endl;
            }
            else
            {
                if(group[a] == -1 && group[b] == -1)
                {
                    list<int> la;
                    list<int> lb;
                    la.push_back(b);
                    lb.push_back(a);
                    vli.push_back(la);
                    group[a] = vli.size() - 1;
                    vli.push_back(lb);
                    group[b] = vli.size() - 1;
                }
                else if(group[a] != -1 && group[b] != -1)
                {
                    int g;
                    g = group[vli[group[a]].front()];
                    list<int>::iterator itr = vli[group[b]].begin();
                    list<int>::iterator end = vli[group[b]].end();
                    itr ++;
                    for(; itr != end; ++itr) group[*itr] = g;
                    itr = ++ vli[group[b]].begin();
                    vli[g].splice(vli[g].end(), vli[group[b]],
                                      itr, vli[group[b]].end());
                    
                    g = group[vli[group[b]].front()];
                    itr = vli[group[a]].begin();
                    end = vli[group[a]].end();
                    itr ++;
                    for(; itr != end; ++itr) group[*itr] = g;
                    itr = ++ vli[group[b]].begin();
                    vli[g].splice(vli[g].end(), vli[group[a]],
                                      itr, vli[group[a]].end());                   
                }
                else
                {
                    if(group[a] != -1)
                    {
                        int g;
                        g = group[vli[group[a]].front()];
                        group[b] = g;
                        vli[g].push_back(b);
                    }
                    else
                    {
                        int g;
                        g = group[vli[group[b]].front()];
                        group[a] = g;
                        vli[g].push_back(a);
                    }
                }
            }
        }
    }
    return 0;
}