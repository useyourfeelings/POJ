#include<iostream>
#include<algorithm>
using namespace std;

struct man
{
    man(){}
    int t, p, s;
};

bool operator<(const man &a, const man &b)
{
    return a.t < b.t;
}

int rec[100];
int N, K, T, i, ans, temp;
man guy[100];

int make(int pos)
{
    if(rec[pos] != -1) return rec[pos];
    int st, i, ret = 0, t;
    for(i = pos + 1; i < N; ++ i)
    {
        if(K < guy[i].s) continue;
        if(T < guy[i].t) break;
        st = guy[i].s - guy[pos].s;
        if(st < 0) st = - st;
        if(st <= guy[i].t - guy[pos].t)
        {
            if((t = make(i))> ret) ret = t;
        }
    }
    ret += guy[pos].p;
    rec[pos] = ret;
    return ret;
    
}

int main()
{
    scanf("%d%d%d", &N, &K, &T);
    for(i = 0; i < N; ++ i) scanf("%d", &guy[i].t);
    for(i = 0; i < N; ++ i) scanf("%d", &guy[i].p);
    for(i = 0; i < N; ++ i) scanf("%d", &guy[i].s);
    for(i = 0; i < N; ++ i) rec[i] = -1;
    sort(guy, guy + N);
    ans = 0;
    for(i = 0; i < N; ++ i)
    {
        if(guy[i].t <= T && guy[i].s <= K && guy[i].s <= guy[i].t)
        {
            if((temp = make(i)) > ans) ans = temp;
        }
    }
    printf("%d", ans);
    return 0;
}