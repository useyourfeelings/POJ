#include<iostream>
#include<algorithm>
using namespace std;

int g[100000];

int main()
{
    int n, i, sz, j;
    scanf("%d%d", &n, &sz);
    for(i = 0; i < n; ++ i) scanf("%d", &g[i]);
    sort(g, g + n);
    j = n - 1;
    i = n = 0;
    while(i <= j)
    {
        if(g[i] + g[j] <= sz)
        {
            ++ i;
            -- j;
        }
        else -- j;
        ++ n;
    }
    printf("%d", n);
    return 0;
}