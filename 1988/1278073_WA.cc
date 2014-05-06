#include<iostream>
#include<list>
using namespace std;

const int n = 30000;
int slot[n + 1];
int val[n + 1];
list<int> g[n + 1];

int main()
{   
    int p, x, y, add;
    char c;
    memset(val, 0, sizeof(val));
    for(add = 1; add <= n; add++)
    {
        slot[add] = add;
        g[add].push_back(add);
    }
    
    cin>>p;
    while(p--)
    {
        scanf("%1s", &c);
        if(c == 'M')
        {
            scanf("%d%d", &x, &y);
            add = val[g[slot[y]].back()] + 1;
            int t = slot[x];
            list<int>::iterator itr = g[slot[x]].begin();
            list<int>::iterator end = g[slot[x]].end();
            for(; itr != end; ++itr)
            {
                val[*itr] += add;
                slot[*itr] = y;
            }
            g[slot[y]].splice(g[slot[y]].end(), g[t]);
        }
        else
        {
            scanf("%d", &x);
            cout<<val[x]<<endl;
        }
    }
    return 0;
}