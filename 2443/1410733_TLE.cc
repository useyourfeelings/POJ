#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int i, j, n, t, s, q;
    scanf("%d", &n);
    vector<vector<int> > d(10001);
    for(i = 1, q = -1; i <= n; ++ i)
    {
        scanf("%d", &t);
        for(j = 0; j < t; ++ j)
        {
            scanf("%d", &s);
            if(s > q) q = s;
            d[s].push_back(i);
        }
    }
    for(i = 1; i <= q; ++ i) sort(d[i].begin(), d[i].end());
    scanf("%d", &q);
    while(q --)
    {
        scanf("%d%d", &n, &t);
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