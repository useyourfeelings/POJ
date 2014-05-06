#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int adj[100][100];

int main()
{   
    int n, i, j;
    while(cin>>n)
    {
        int sum = 0;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++) cin>>adj[i][j];
        vector<bool> done(n, 0);
        vector<int> got;
        got.reserve(n);
        got.push_back(0);
        done[0] = 1;
        while(got.size() != n)
        {
            int min = INT_MAX, minid;
            vector<int>::iterator itr = got.begin();
            vector<int>::iterator end = got.end();
            for(; itr != end; ++itr)
            {
                for(i = 0; i < n; i++)
                {
                    if(done[i] || i == *itr) continue;
                    if(adj[*itr][i] < min)
                    {
                        min = adj[*itr][i];
                        minid = i;
                    }
                }
            }
            sum += min;
            got.push_back(minid);
            done[minid] = 1;
        }
        cout<<sum<<endl;
    }
    return 0;
}