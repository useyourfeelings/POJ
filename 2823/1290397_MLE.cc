#include<iostream>
#include<cmath>
using namespace std;

int n, k, i, kk;
int a[1000000];
int d[1000000][20];
int g[1000000][20];

void make()
{
    for(int j = 1; j <= int(log2(n)); ++ j)
    {
        for(int i = 0; i < n; ++ i)
        {
            d[i][j] = min(d[i][j - 1],
                d[i + int(pow(2.0, j - 1))][j - 1]);
            g[i][j] = max(g[i][j - 1],
                g[i + int(pow(2.0, j - 1))][j - 1]);
        }
    }
}

int main()
{   
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        g[i][0] = d[i][0] = a[i];
    }
    make();
    kk = log2(k);
    for(i = 0; i <= n - k; ++ i)
    {
        printf("%d ", min(d[i][kk],
                d[i + k - int(pow(2.0, kk))][kk]));
    }
    printf("\n");
    for(i = 0; i <= n - k; ++ i)
    {
        printf("%d ", max(g[i][kk],
                g[i + k - int(pow(2.0, kk))][kk]));
    }
    return 0;
}