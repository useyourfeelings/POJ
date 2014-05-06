#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int i, j, n, t, s, q;
    scanf("%d", &n);
    vector<vector<int> > d(10001);
    vector<bool> ok(10001, 0);
    for(i = 1, q = -1; i <= n; ++ i)
    {
        scanf("%d", &t);
        for(j = 0; j < t; ++ j)
        {
            scanf("%d", &s);
            d[s].push_back(i);
        }
    }
    scanf("%d", &q);
    while(q --)
    {
        scanf("%d%d", &n, &t);
        if(!ok[n])
        {
            sort(d[n].begin(), d[n].end());
            ok[n] = 1;
        }
        if(!ok[t])
        {
            sort(d[t].begin(), d[t].end());
            ok[t] = 1;
        }
        for(i = j = 0, s = -2; i < d[n].size() && j < d[t].size();)
        {
            if(d[n][i] == d[t][j])
            {
                s = -1;
                break;
            }
            else if(d[n][i] > d[t][j]) ++ j;
            else ++ i;
        }
        if(s == -1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}