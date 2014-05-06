#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main()
{
    int i, j, n, t, s, q;
    scanf("%d", &n);
    vector<set<int> > d(10001);
    for(i = 1, q = -1; i <= n; ++ i)
    {
        scanf("%d", &t);
        for(j = 0; j < t; ++ j)
        {
            scanf("%d", &s);
            d[s].insert(i);
        }
    }
    scanf("%d", &q);
    while(q --)
    {
        scanf("%d%d", &n, &t);
        set<int>::iterator in = d[n].begin(), it = d[t].begin(),
                           en = d[n].end(), et = d[t].end();
        for(s = -2; in != en && it != et;)
        {
            if(*in == *it)
            {
                s = -1;
                break;
            }
            else if(*in > *it) ++ it;
            else ++ in;
        }
        if(s == -1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}