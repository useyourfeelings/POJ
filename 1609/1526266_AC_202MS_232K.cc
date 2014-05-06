#include<iostream>
#include<algorithm>
using namespace std;

bool comp(const int& a, const int& b)
{
    if((a / 1000) != (b / 1000)) return (a / 1000) > (b / 1000);
    return a % 1000 > b % 1000;
}

int g[10000];
int record[10000];
int i, n, a, b;

int make(int now)
{
    if(record[now] != -1) return record[now];
    int t, maxh = 1;
    for(int j = now + 1; j < n; ++ j)
    {
        if(g[j] % 1000 <= g[now] % 1000)
            if((t = make(j) + 1) > maxh) maxh = t;
    }
    record[now] = maxh;
    return maxh;
}

int main()
{
    while(scanf("%d", &n) && n != 0)
    {
        for(i = 0; i < n; ++ i)
        {
            scanf("%d%d", &a, &b);
            g[i] = a * 1000 + b;
            record[i] = -1;
        }
        sort(g, g + n, comp);
        a = 1;
        for(i = 0; i < n - 1; ++ i)
            if((b = make(i)) > a) a = b;
        printf("%d\n", a);
    }
    printf("*");
    return 0;
}