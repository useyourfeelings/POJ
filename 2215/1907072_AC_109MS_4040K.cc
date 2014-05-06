#include<iostream>
using namespace std;
int map[1000][1000];
int test, R, C, i, j, sum, r1, r2, c1, c2, n;
int main()
{
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d%d", &R, &C);
        for(i = 0; i < R; ++ i)
            for(j = 0; j < C; ++ j)
                scanf("%d", &map[i][j]);
        scanf("%d", &n);
        while(n --)
        {
            scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
            sum = 0;
            for(i = r1 - 1; i < r2; ++ i)
                for(j = c1 - 1; j < c2; ++ j) sum += map[i][j];
            printf("Absolutni hodnota pohodlnosti je %d bodu.\n", sum);
        }
        printf("\n");
    }
    return 0;
}