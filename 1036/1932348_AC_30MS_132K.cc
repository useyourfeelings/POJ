#include<iostream>
#include<algorithm>
using namespace std;
struct man {man(){} int t, p, s;};
bool operator<(const man &a, const man &b) {return a.t < b.t;}
int rec[100];
man guy[100];
int main()
{
    int N, K, T, i, j, temp, max, st;
    scanf("%d%d%d", &N, &K, &T);
    for(i = 0; i < N; ++ i) scanf("%d", &guy[i].t);
    for(i = 0; i < N; ++ i) scanf("%d", &guy[i].p);
    for(i = 0; i < N; ++ i) scanf("%d", &guy[i].s);
    sort(guy, guy + N);
    while(N >= 1 && guy[N - 1].t > T) -- N;
    for(i = N - 1; i >= 0; -- i)
    {
        for(max = 0, j = i + 1; j < N; ++ j)
        {
            if(K < guy[j].s) continue;
            st = guy[j].s - guy[i].s;
            if(st < 0) st = - st;
            if(st <= guy[j].t - guy[i].t)
                if(rec[j] > max) max = rec[j];
        }
        rec[i] = max + guy[i].p;
    }
    for(max = 0, i = N - 1; i >= 0; -- i)
        if(guy[i].s <= K && guy[i].s <= guy[i].t)
            if(rec[i] > max) max = rec[i];
    printf("%d", max);
    return 0;
}