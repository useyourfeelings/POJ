#include<iostream>
using namespace std;

int a[26], b[26];

int main()
{
    int n, i, j, count;
    char t;
    cin>>n;
    getchar();
    for(i = 1; i <= n; ++ i)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        while(scanf("%c", &t) && t != '\n') ++ a[t - 97];
        while(scanf("%c", &t) && t != '\n') ++ b[t - 97];
        for(j = 0, count = 0; j < 26; ++ j)
            count += abs(a[j] - b[j]);
        printf("Case #%d:  %d\n", i, count);
    }
    return 0;
}