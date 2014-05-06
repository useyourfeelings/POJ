#include<iostream>
#include<algorithm>
using namespace std;

int x[10000], y[10000];

int main()
{
    int n, i, k, step = 0, mid;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i) scanf("%d%d", &x[i], &y[i]);
    sort(x, x + n);
    sort(y, y + n);
    mid = x[n / 2];
    k = n / 2;
    for(i = n / 2 - 1; i >= 0; -- i) step += abs(mid - k + i - x[i]);
    for(i = n / 2 + 1; i < n; ++ i)  step += abs(mid + i - k - x[i]);
    mid = y[n / 2];
    for(i = n / 2 - 1; i >= 0; -- i) step += (mid - y[i]);
    for(i = n / 2 + 1; i < n; ++ i)  step += (y[i] - mid);
    printf("%d", step);
    return 0;
}