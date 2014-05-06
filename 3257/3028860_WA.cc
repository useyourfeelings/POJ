#include<iostream>
#include<vector>
using namespace std;

struct info
{
    int len, fun, cost;
    info(int l, int f, int c):len(l),fun(f),cost(c){}
};

long long rec[1000][1001];
int L, N, B, i, x, w, f, c;
vector<vector<info> > roller;

long long dp(int pos, int cost)
{
    if(pos >= L || cost > B) return 0;
    if(rec[pos][cost] != -1) return rec[pos][cost];
    long long maxfun = 0, t;
    i = roller[pos].size();
    if(i == 0)
    {
        rec[pos][cost] = 0;
        return 0;
    }
    for(-- i; i >= 0; -- i)
    {
        t = roller[pos][i].fun + 
            dp(pos + roller[pos][i].len, cost + roller[pos][i].cost);
        if(t > maxfun)
            maxfun = t;
    }
    rec[pos][cost] = maxfun;
    return maxfun;
}

int main()
{
    scanf("%d%d%d", &L, &N, &B);
    roller.resize(N + 1);
    for(i = 0; i < N; ++ i)
    {
        scanf("%d%d%d%d", &x, &w, &f, &c);
        roller[x].push_back(info(w, f, c));
    }
    for(i = 0; i < L; ++ i)
        for(x = 0; x <= 1000; ++ x)
            rec[i][x] = -1;
    cout<<dp(0, 0)<<endl;
    return 0;
}