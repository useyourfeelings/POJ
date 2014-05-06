#include<iostream>
#include<vector>
#include<limits>
#include<set>
using namespace std;

int g[501][501];
int d[501];

int main()
{   
    int f, p, c, m, i, j, a, b, wt, mindis, who;
    scanf("%d%d%d%d", &f, &p, &c, &m);
    set<int> UnDoneSet;
    set<int>::iterator itr;
    for(i = 1; i <= f; i++)
    {
        for(j = 1; j <= f; j++)
            g[i][j] = g[j][i] = INT_MAX;
        d[i] = INT_MAX;
        UnDoneSet.insert(i);
    }
    for(i = 0; i < p; i ++)
    {
        scanf("%d%d%d", &a, &b, &wt);
        if(wt < g[a][b]) g[a][b] = g[b][a] = wt;
    }
    vector<int> LocationOfCow(c + 1);
    vector<int> CowInField(f + 1, 0);
    for(i = 1; i <= c; i++)
    {
        scanf("%d", &LocationOfCow[i]);
        ++ CowInField[LocationOfCow[i]];
    }
    d[1] = 0;
    vector<bool> done(f + 1, false);
    b = 0; // field count
    a = 0; // cow count
    for(;;)
    {
        mindis = INT_MAX;
        for(itr = UnDoneSet.begin(); itr != UnDoneSet.end(); ++ itr)
        {
            if(d[*itr] < mindis)
            {
                mindis = d[*itr];
                who = *itr;
            }
        }
        if(d[who] <= m) a += CowInField[who];
        UnDoneSet.erase(who);
        done[who] = true;
        if(++ b == f) break;
        for(i = 1; i <= f; ++ i)
        {
            if(done[i] || g[i][who] == INT_MAX) continue;
            if(d[who] + g[who][i] < d[i])
                d[i] = d[who] + g[who][i];
        }
    }
    printf("%d\n", a);
    for(i = 1; i <= c; ++ i)
        if(d[LocationOfCow[i]] <= m) printf("%d\n", i);
    return 0;
}