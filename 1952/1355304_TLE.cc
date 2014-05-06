#include<iostream>
#include<vector>
#include<set>
using namespace std;

short i, j, k, n, maxv, maxl = -1;
vector<short> g;
vector<short> gg;
vector<short> maxlen;
vector<vector<short> > next;

void make(vector<short> v)
{
    if(v.size() == 0) return;
    else
    {
        k *= v.size();
        for(int i = 0; i < v.size(); ++ i) make(next[v[i]]);
    }
}

int main()
{
    scanf("%d", &n);
    g.resize(n);
    next.resize(n);
    maxlen.resize(n);
    for(i = 0; i < n; ++ i) scanf("%d", &g[i]);
    for(i = n - 1; i >= 0; -- i)
    {
        maxv = 0;
        vector<short> can;
        set<short> own;
        for(j = i; j < n; ++ j)
        {
            if(g[j] < g[i])
            {
                if(maxlen[j] > maxv)
                {
                    can.clear();
                    own.clear();
                    can.push_back(j);
                    own.insert(g[j]);
                    maxv = maxlen[j];
                }
                else if(maxlen[j] == maxv)
                {
                    if (own.find(g[j]) == own.end())
                    {
                        can.push_back(j);
                        own.insert(g[j]);
                    }
                }
            }
        }
        next[i] = can;
        maxlen[i] = maxv + 1;
        if(maxlen[i] > maxl)
        {
            gg.clear();
            gg.push_back(i);
            maxl = maxlen[i];
        }
        else if(maxlen[i] == maxl) gg.push_back(i);
    }
    for(i = j = 0; i < gg.size(); ++ i)
    {
        k = 1;
        make(next[gg[i]]);
        j += k;
    }
    printf("%d %d", maxl, j);
    return 0;
}