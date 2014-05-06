#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

const int infinity = 70001;
int g[501][501];

int main()
{   
    int f, p, c, m, i, j, a, b, wt;
    scanf("%d%d%d%d", &f, &p, &c, &m);
    for(i = 1; i <= f; i++)
        for(j = 1; j <= f; j++)
            g[i][j] = infinity;
    for(i = 0; i < p; i++)
    {
        scanf("%d%d%d", &a, &b, &wt);
        g[a][b] = g[b][a] = wt;
    }
    
    vector<int> locationOf(c + 1);
    vector<bool> haveCow(f + 1, 0);
    for(i = 1; i <= c; i++)
    {
        scanf("%d", &locationOf[i]);
        haveCow[locationOf[i]] = 1;
    }
    
    b = 0;
    
    vector<int> d(f + 1);
    for(i = 1; i <= f; i++) d[i] = g[1][i];
    
    set<int> done;
    done.insert(1);
    if(haveCow[1]) b ++;
    
    map<int, int> bad;
    for(i = 2; i <= f; i++)
        bad.insert(make_pair(i, d[i]));
    
    for(i = 1; i < f; i++)
    {
        a = bad.begin() -> first;
        bad.erase(bad.begin());
        done.insert(a);
        if(haveCow[a] && d[a] <= m) b ++;
        for(j = 1; j <= f; j++)
        {
            if(done.find(j) == done.end())
                if(d[a] + g[a][j] < d[j])
                    d[j] = d[a] + g[a][j];
        }
    }
    cout<<b<<endl;
    for(i = 1; i <= c; i++)
        if(d[locationOf[i]] <= m ||
                locationOf[i] == 1) cout<<i<<endl;
    return 0;
}