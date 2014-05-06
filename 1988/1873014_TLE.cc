#include<iostream>
#include<list>
using namespace std;

int slot[30001];
int val[30001];
list<int> g[30001];

int main()
{   
    int p, x, y, add;
    char op;
    memset(val, 0, sizeof(val));
    for(add = 1; add <= 30000; add ++)
    {
        slot[add] = add;
        g[add].push_back(add);
    }
    scanf("%d", &p);
    getchar();
    while(p --)
    {
        scanf("%c", &op);
        if(op == 'M')
        {
            scanf("%d%d", &x, &y);
            getchar();
            add = g[slot[y]].size();
            int t = slot[x];
            list<int>::iterator itr = g[t].begin();
            list<int>::iterator end = g[t].end();
            for(; itr != end; ++itr)
            {
                val[*itr] += add;
                slot[*itr] = slot[y];
            }
            g[slot[y]].splice(g[slot[y]].end(), g[t]);
        }
        else
        {
            scanf("%d", &x);
            getchar();
            cout<<val[x]<<endl;
        }
    }
    return 0;
}