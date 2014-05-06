#include<iostream>
#include<algorithm>
using namespace std;

int i, A, B, K, t, p;

struct future
{
    int a;
    int b;
    int c;
};

bool operator<(const future &x, const future &y)
{
    return x.a < y.a;
}

future service[100];
int MinBFrom[100];
int record[101][101][101];

int make(int remaina, int remainb, int pos)
{
    if(pos >= K) return -1;
    if(record[remaina][remainb][pos] != -2)
        return record[remainb][remainb][pos];
    if(service[pos].a > remaina || MinBFrom[pos] > remainb) return -1;
    int doit, pass = make(remaina, remainb, pos + 1);
    int ra = remaina - service[pos].a;
    int rb = remainb - service[pos].b;
    if(ra == 0 && rb == 0) doit = service[pos].c;
    else if(rb < 0)        doit = -1;
    else
    {
        if((rb = make(ra, rb, pos + 1)) != -1)
            doit =  rb + service[pos].c;
        else doit = -1;
    }
    if(pass == -1 && doit == -1) ra = -1;
    else if(pass == -1)          ra = doit;
    else if(doit == -1)          ra = pass;
    else                         ra = min(doit, pass);
    record[remaina][remainb][pos] = ra;
    return ra;
}

int main()
{
    while(scanf("%d%d%d", &A, &B, &K) && A != 0)
    {
        for(i = 0; i < K; ++ i)
            scanf("%d%d%d", &service[i].a, &service[i].b, &service[i].c);
        sort(service, service + K);
        t = MinBFrom[K - 1] = service[K - 1].b;
        for(i = K - 1; i >= 0; -- i)
        {
            if(service[i].b < t) t = service[i].b;
            MinBFrom[i] = t;
        }
        for(t = 0; t <= A; ++ t)
            for(p = 0 ; p <= B; ++ p)
                for(i = 0; i <= K; ++ i) record[t][p][i] = -2;
        printf("%d\n", make(A, B, 0));
    }
    return 0;
}