#include<iostream>
#include<algorithm>
using namespace std;
int v[128];
int main()
{
    int K, i, t;
    scanf("%d", &K);
    for(i = 0; i < K; ++ i) scanf("%d", &v[i]);
    sort(v, v + K);
    K = K / 2 + 1;
    for(i = t = 0; i < K; ++ i) t += v[i] / 2;
    printf("%d\n", t + K);
    return 0;
}