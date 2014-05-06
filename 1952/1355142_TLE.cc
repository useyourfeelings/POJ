#include<iostream>
#include<vector>
using namespace std;

short i, j, k, n, maxv;
vector<short> g;
vector<short> maxlen;
vector<vector<short> > next;

void make(short start, vector<short> v)
{
    if(v.size() == 0) return;
    else
    {
        k *= v.size();
        for(int i = 0; i < v.size(); ++ i) make(v[i], next[v[i]]);
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
                else if(maxlen[j] == maxv)
                {
                    for(k = 0; k < can.size(); ++ k)
                        if(g[can[k]] == g[j]) break;
                    if (k >= can.size()) can.push_back(j);
                }
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
    for(i = j = 0; i < gg.size(); ++ i)
    {
        k = 1;
        make(gg[i], next[gg[i]]);
        j += k;
    }
    printf("%d %d", maxv, j);
    return 0;
}