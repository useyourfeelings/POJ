#include<iostream>
#include<algorithm>
using namespace std;
int r[1000];
int main()
{
    int i, n, j, k, maxw;
    scanf("%d", &n);
    for(i = 0; i< n; ++i)
    {
        scanf("%d", &k);
        for(j = 0; j < k; ++ j) scanf("%d", &r[j]);
        sort(r, r + k);
        for(j = 0, maxw = 0; j < k; ++ j)
            if(r[j] * (k - j) > maxw) maxw = r[j] * (k - j);
        printf("%d\n", maxw);
    }
    return 0;
}