#include<iostream>
#include<vector>
using namespace std;

short i, j, n, maxv;
vector<short> g;
vector<short> maxlen;
vector<vector<short> > next;
vector<vector<short> > get;

void load(short start, vector<short> v)
{
    short i;
    v.push_back(g[start]);
    if(next[start].size() == 0)
    {
        for(i = 0; i < get.size(); ++ i)
            if(get[i] == v) break;
        if(i >= get.size()) get.push_back(v);
    }
    else
    {
        for(i = 0; i < next[start].size(); ++ i)
        {
            load(next[start][i], v);
        }
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
        for(j = i; j < n; ++ j)
        {
            if(g[j] < g[i])
            {
                if(maxlen[j] > maxv)
                {
                    can.clear();
                    can.push_back(j);
                    maxv = maxlen[j];
                }
                else if(maxlen[j] == maxv) can.push_back(j);
            }
        }
        next[i] = can;
        maxlen[i] = maxv + 1;
    }
    vector<short> gg;
    maxv = -1;
    for(i = 0; i < n; ++ i)
    {
        if(maxlen[i] > maxv)
        {
            gg.clear();
            gg.push_back(i);
            maxv = maxlen[i];
        }
        else if(maxlen[i] == maxv) gg.push_back(i);
    }
    for(i = 0; i < gg.size(); ++ i) load(i, vector<short>());
    printf("%d %d", maxv, get.size());
    return 0;
}