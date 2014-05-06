#include<iostream>
#include<algorithm>
using namespace std;

short v[100000];

int main()
{
    int i, n, t;
    char x, y[4];
    scanf("%d", &n);
    for(i = 0; i < n; ++ i) scanf("%d", &v[i]);
    gets(y);
    gets(y);
    sort(v, v + n);
    scanf("%d", &n);
    for(i = 0; i < n; ++ i)
    {
        scanf("%d", &t);
        printf("%d\n", v[t - 1]);
    }
    return 0;
}