#include<iostream>
#include<algorithm>
using namespace std;

short g[100][2000];
short head[100];

int main()
{   
    int test, m, n, i, j, sum, diff, who, t;
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d%d", &m, &n);
        for(i = 0; i < m; ++ i)
        {
            for(j = 0; j < n; ++ j) scanf("%d", &g[i][j]);
            sort(g[i], g[i] + n);
            head[i] = 0;
        }
        sum = 0;
        for(i = 0; i < m; ++ i) sum += g[i][0];
        printf("%d\n", sum);
        for(i = 1; i < n; ++ i)
        {
            diff = 100000;
            for(j = 0; j < m; ++ j)
                if(head[j] < n - 1)
                    if((t = g[j][head[j] + 1] - g[j][head[j]]) < diff)
                    {
                        diff = t;
                        who = j;
                    }
            ++ head[who];
            sum += diff;
            printf("%d\n", sum);
        }
    }
    return 0;
}