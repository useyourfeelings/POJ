#include<iostream>
#include<algorithm>
using namespace std;

struct Road
{
    int a, b;
};

bool operator<(const Road& x, const Road& y)
{
    if(x.a == y.a) return x.b < y.b;
    return x.a < y.a;
}

int N;
int sum[1024];
Road roads[1000000];

void add(int pos, int d)
{
    while(pos <= N)
    {
        sum[pos] += d;
        pos += (pos & (- pos));
    }
}

int getsum(int pos)
{
    int s = 0;
    while(pos > 0)
    {
        s += sum[pos];
        pos -= (pos & (- pos));
    }
    return s;
}

int main()
{
    int test, n, k, i, total, s;
    scanf("%d", &n);
    for(test = 1; test <= n; ++ test)
    {
        scanf("%d%d%d", &i, &N, &k);
        if(N < i) N = i;
        for(i = 0; i < k; ++ i) sum[i] = 0;
        for(i = 0; i < k; ++ i)
            scanf("%d%d", &roads[i].a, &roads[i].b);
        sort(roads, roads + k);
        total = 0;
        for(i = 0; i < k; ++ i)
        {
            s = getsum(k);
            s -= getsum(roads[i].b);
            total += s;
            add(roads[i].b, 1);
        }
        printf("Test case %d: %d\n", test, total);
    }
    return 0;
}