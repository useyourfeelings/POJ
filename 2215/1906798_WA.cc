#include<iostream>
using namespace std;

int sum[1000000];
int map[1000][1000];
int test, R, C, i, j, r1, r2, c1, c2;

int build(int a, int b, int c, int d, int pos)
{
    int total;
    if(a == c && b == d) total = sum[pos] = map[a][b];
    else
    {
        int s1 = 0, s2 = 0, s3 = 0,  s4 = 0;
        s1 = build(a, b, (a + c) / 2, (b + d) / 2, pos * 4 + 1);
        if(b != d) s2 = build(a, (b + d) / 2 + 1, (a + c) / 2, d, pos * 4 + 2);
        if(a != c) s3 = build((a + c) / 2 + 1, b, c, (b + d) / 2, pos * 4 + 3);
        if(b != d && a != c)
            s4 = build((a + c) / 2 + 1, (b + d) / 2 + 1,
                                    c, d, pos * 4 + 4);
        total = s1 + s2 + s3 + s4;
    }
    sum[pos] = total;
    return total;
}

void query(int a, int b, int c, int d, int pos)
{
    if(a > r2 || c < r1 || b > c2 || d < c1) return;
    if(a >= r1 && c <= r2 && b >= c1 && d <= c2)
    {
        j += sum[pos];
        return;
    }
    query(a, b, (a + c) / 2, (b + d) / 2, pos * 4 + 1);
    if(b != d) query(a, (b + d) / 2 + 1, (a + c) / 2, d, pos * 4 + 2);
    if(a != c) query((a + c) / 2 + 1, b, c, (b + d) / 2, pos * 4 + 3);
    if(b != d && a != c) query((a + c) / 2 + 1,
                               (b + d) / 2 + 1, c, d, pos * 4 + 4);
}

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d%d", &R, &C);
        for(i = 0; i < R; ++ i)
            for(j = 0; j < C; ++ j)
                scanf("%d", &map[i][j]);
        build(0, 0, R - 1, C - 1, 0);
        scanf("%d", &i);
        while(i --)
        {
            scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
            -- r1, -- r2, -- c1, -- c2;
            j = 0;
            query(0, 0, R - 1, C - 1, 0);
            printf("Absolutni hodnota pohodlnosti je %d bodu.\n", j);
        }
        printf("\n");
    }
    return 0;
}