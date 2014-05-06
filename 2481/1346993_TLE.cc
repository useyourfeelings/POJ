#include<iostream>
using namespace std;

int s[100000];
int e[100000];
int strong[100000];

int main()
{   
    int n, i, j;
    while(scanf("%d", &n) && n != 0)
    {
        for(i = 0; i < n; ++ i) scanf("%d%d", &s[i], &e[i]);
        memset(strong, 0, sizeof(int) * n);
        for(i = 0; i < n - 1; ++ i)
        {
            for(j = 1; j < n; ++ j)
            {
                if(e[i] - s[i] > e[j] - s[j])
                {
                    if(s[i] <= s[j] && e[i] >= e[j]) ++ strong[j];
                }
                else if(e[i] - s[i] < e[j] - s[j])
                {
                    if(s[i] >= s[j] && e[i] <= e[j]) ++ strong[i];
                }
            }
        }
        for(i = 0; i < n; ++ i) printf("%d ", strong[i]);
        printf("\n");
    }
    return 0;
}