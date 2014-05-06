#include<iostream>
#include<algorithm>
using namespace std;

int x[10000], y[10000], z[10000];

int main()
{
    int n, i, step = 0, mid;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i) scanf("%d%d", &x[i], &y[i]);
    for(i = 0; i < n; ++ i) z[i] = x[i] - i;
    sort(x, x + n);
    sort(y, y + n);
    sort(z, z + n);
    mid = z[n / 2];
    for(i = 0; i < n; ++ i) step += abs(mid + i - x[i]);
    mid = y[n / 2];
    for(i = n / 2 - 1; i >= 0; -- i) step += (mid - y[i]);
    for(i = n / 2 + 1; i < n; ++ i)  step += (y[i] - mid);
    printf("%d", step);
    return 0;
}