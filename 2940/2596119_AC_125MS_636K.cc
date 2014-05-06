#include<iostream>
using namespace std;

int a[100001];

int main()
{
    int i, n;
    long long total;
    while(scanf("%d", &n) && n != 0)
    {
        total = 0;
        for(i = 0; i < n; ++ i) scanf("%d", &a[i]);
        for(i = 0; i < n; ++ i)
        {
            if(a[i] > 0) total += a[i];
            else         total -= a[i];
            a[i + 1] += a[i];
        }
        printf("%I64d\n", total);
    }
    return 0;
}
