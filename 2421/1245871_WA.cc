#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int main()
{
    int g[101][101];
    int n, q, i, j;
    cin>>n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            cin>>g[i][j];
    cin>>q;
    vector<int> got;
    vector<bool> done(n + 1, 0);
    
    while(q--)
    {
        cin>>i>>j;
        if(!done[i])
        {
            got.push_back(i);
            done[i] = 1;
        }
        if(!done[j])
        {
            got.push_back(j);
            done[j] = 1;
        }
    }
    
    int mstwt = 0;
    while(got.size() != n)
    {
        int minw = INT_MAX;
        int willget;
        vector<int>::iterator itr = got.begin();
        vector<int>::iterator end = got.end();
        for(; itr != end; ++itr)
        {
            for(i = 1; i <= n; i++)
            {
                if(!done[i] && i != *itr)
                {
                    if(g[*itr][i] < minw)
                    {
                        willget = i;
                        minw = g[*itr][i];
                    }
                }
            }
        }
        got.push_back(willget);
        done[willget] = 1;
        mstwt += minw;
    }
    cout<<mstwt<<endl;
    return 0;
}